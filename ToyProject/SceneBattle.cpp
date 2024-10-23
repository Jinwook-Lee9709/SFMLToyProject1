#include "stdafx.h"
#include "SceneBattle.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include "TextGo.h"
#include "SpriteGo.h"

SceneBattle::SceneBattle()
	:Scene(SceneIds::Battle), turn(Turn::CardSelect)
{
}

SceneBattle::~SceneBattle()
{
}

void SceneBattle::Init(sf::RenderWindow& window)
{
	this->window = &window;
	auto* background = AddGo(new SpriteGo("graphics/Background.png"));
	background->SetOrigin(Origins::MC);
	background->SetPosition({ window.getSize().x * 0.5f, window.getSize().y * 0.5f -100.f});
	auto* cost = AddGo(new SpriteGo("graphics/Cost.png"));
	cost->SetOrigin(Origins::MC);
	cost->SetPosition({ window.getSize().x * 0.14f, window.getSize().y * 0.6f });
	auto* obj1 = AddGo(new Player("graphics/Ironclad.png"));
;	obj1->SetOrigin(Origins::BC);
	obj1->SetPosition({ window.getSize().x * 0.25f, window.getSize().y * 0.6f});
	auto* obj2 = AddGo(new Enemy("graphics/Golem.png"));
	obj2->SetOrigin(Origins::BC);
	obj2->SetPosition({ window.getSize().x * 0.75f, window.getSize().y * 0.6f });
	sf::Vector2f cardPos(window.getSize().x * 0.25f, window.getSize().y * 0.95f);
	sf::Vector2f cardGap(200.f, 0.f);
	for (int i = 0; i < 5; i++) {
		auto* obj = AddGo(new Card("graphics/Strike.png"));
		obj->SetOrigin(Origins::BC);
		obj->SetPosition(cardPos);
		obj->SetCardType(Cards::Strike);
		obj->SetScale(sf::Vector2f(0.3f, 0.3f));
		obj->SetName("Card" + std::to_string(i));
		cardPos += cardGap;
	}
	
	Scene::Init(window);
}

void SceneBattle::Enter()
{
	RES_MGR(sf::Texture).Load("graphics/Background.png");
	RES_MGR(sf::Texture).Load("graphics/Cost.png");
	RES_MGR(sf::Texture).Load("graphics/Ironclad.png");
	RES_MGR(sf::Texture).Load("graphics/Golem.png");
	RES_MGR(sf::Texture).Load("graphics/Bash.png");
	RES_MGR(sf::Texture).Load("graphics/Defend.png");
	RES_MGR(sf::Texture).Load("graphics/Inflame.png");
	RES_MGR(sf::Texture).Load("graphics/Strike.png");
	RES_MGR(sf::Font).Load("fonts/Sansation.ttf");
	
	
	Scene::Enter();
}

void SceneBattle::Exit()
{
	RES_MGR(sf::Texture).Load("graphics/Background.png");
	RES_MGR(sf::Texture).Load("graphics/Cost.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Ironclad.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Golem.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Bash.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Defend.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Inflame.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Strike.png");
	RES_MGR(sf::Font).UnLoad("fonts/Sansation.ttf");
}



void SceneBattle::Update(float dt)
{
	auto pobj = FindGo("Player");
	auto player = (Player*)pobj;
	auto eobj = FindGo("Golem");
	auto enemy = (Enemy*)eobj;
	std::deque<Card*> card_list;
	for (int i = 0; i < 5; i++) {
		auto tempCard = (Card*)FindGo("Card" + std::to_string(i));
		tempCard->UpdateCard(player->GetAtk());
		card_list.push_back(tempCard);
	}
	//입력대기 / 플레이어턴 진행 / 적 턴 진행 / 적 행동결정
	switch (turn) {
	case Turn::CardSelect: {
		if (player->GetCost() > 0 && InputManager::GetBtnPressed(sf::Mouse::Left)) {
			for (int i = 0; i < 5; i++) {
				auto it = card_list.front();
				if (it->CheckPos(InputManager::GetMousePosWindow(window))) {
					it->selected();
					selectedCard = i;
					turn = Turn::MonsterSelect;
					break;
				}
				card_list.pop_front();
			}
		}
		break;
	}
	case Turn::MonsterSelect: {
		if (InputManager::GetBtnPressed(sf::Mouse::Left)) {
			auto card = (Card*)FindGo("Card" + std::to_string(selectedCard));
			if (card->getType() != Cards::Bash && card->getType() != Cards::Strike) {
				if (player->CheckPos(InputManager::GetMousePosWindow(window))) {
					PlayerAction(*player, *enemy, *card);
					card->unSelected();
					player->UseCost(card->getType());
					turn = Turn::CardSelect;
				}
			}
			else {
				if (enemy->CheckPos(InputManager::GetMousePosWindow(window))) {
					PlayerAction(*player, *enemy, *card);
					card->unSelected();
					player->UseCost(card->getType());
					turn = Turn::CardSelect;
				}
			}
		}
		if (InputManager::GetKeyPressed(sf::Keyboard::Num9)) {
			auto obj = FindGo("Card0");
			auto card = (Card*)obj;
			card->unSelected();
			turn = Turn::CardSelect;
		}
		break;
	}
	case Turn::MonsterTurn: {
		
		break;
	}
	}
	
	Scene::Update(dt);
}

void SceneBattle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneBattle::PlayerAction(Player& player, Enemy& enemy, Card& card)
{
	switch (card.getType()) {
		case Cards::Bash: {
			enemy.Hit(8 + player.GetAtk());
			break;
		}
		case Cards::Defend: {
			player.GetShield(5);
			break;
		}
		case Cards::Inflame: {
			player.BufAtk(2);
			break;
		}
		case Cards::Strike: {
			enemy.Hit(6 + player.GetAtk());
			break;
		}
	}
}




//if (InputManager::GetKeyPressed(sf::Keyboard::Num1)) {
//	auto obj = FindGo("Player");
//	auto player = (Player*)obj;
//	player->Hit(20);
//}
//if (InputManager::GetKeyPressed(sf::Keyboard::Num2)) {
//	auto obj = FindGo("Player");
//	auto player = (Player*)obj;
//	player->Heal(20);
//}
//if (InputManager::GetKeyPressed(sf::Keyboard::Num3)) {
//	auto obj = FindGo("Golem");
//	auto Golem = (Enemy*)obj;
//	Golem->Hit(20);
//}