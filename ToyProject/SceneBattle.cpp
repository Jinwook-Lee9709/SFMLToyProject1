#include "stdafx.h"
#include "SceneBattle.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "CardPile.h"

SceneBattle::SceneBattle()
	:Scene(SceneIds::Battle), turn(Turn::CardSelect)
{
}

SceneBattle::~SceneBattle()
{
}

void SceneBattle::Init(sf::RenderWindow& window)
{
	DECK_CTRL.Init();
	this->window = &window;
	auto* background = AddGo(new SpriteGo("graphics/Background.png"));
	background->SetOrigin(Origins::MC);
	background->SetPosition({ window.getSize().x * 0.5f, window.getSize().y * 0.5f -100.f});
	auto* cost = AddGo(new SpriteGo("graphics/Cost.png"));
	cost->SetOrigin(Origins::MC);
	cost->SetPosition({ window.getSize().x * 0.14f, window.getSize().y * 0.6f });

	auto* obj1 = AddGo(new Player("graphics/Ironclad.png"));
	obj1->SetOrigin(Origins::BC);
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
	auto* obj3 = AddGo(new CardPile("graphics/Deck.png", "Deck"));
	obj3->SetOrigin(Origins::MC);
	obj3->SetPosition({ window.getSize().x * 0.1f, window.getSize().y * 0.9f });
	obj3->SetScale(sf::Vector2f(0.3f, 0.3f));

	auto* obj4 = AddGo(new CardPile("graphics/Deck.png", "Grave"));
	obj4->SetOrigin(Origins::MC);
	obj4->SetPosition({ window.getSize().x * 0.9f, window.getSize().y * 0.9f });
	obj4->SetScale(sf::Vector2f(0.3f, 0.3f));

	auto* end = AddGo(new SpriteGo("graphics/End.png","EndButton"));
	end->SetOrigin(Origins::MC);
	end->SetPosition({ window.getSize().x * 0.9f, window.getSize().y * 0.75f });
	end->SetScale(sf::Vector2f(0.3f, 0.3f));

	auto* gameover = AddGo(new TextGo("fonts/Sansation.ttf"));
	gameover->SetName("GAMEOVER");
	gameover->SetText("GameOver Press button to Restart");
	gameover->SetOrigin(Origins::MC);
	gameover->SetPosition({ window.getSize().x * 0.5f, window.getSize().y * 0.3f });
	gameover->SetSize(50);
	gameover->SetActive(false);

	auto* victory = AddGo(new TextGo("fonts/Sansation.ttf"));
	victory->SetName("VICTORY");
	victory->SetText("VICTORY! Press button to Restart");
	victory->SetOrigin(Origins::MC);
	victory->SetPosition({ window.getSize().x * 0.5f, window.getSize().y * 0.3f });
	victory->SetSize(50);
	victory->SetActive(false);

	auto* restart = AddGo(new SpriteGo("graphics/Restart.png", "RestartButton"));
	restart->SetOrigin(Origins::MC);
	restart->SetPosition({ window.getSize().x * 0.5f, window.getSize().y * 0.5f });
	restart->SetScale(sf::Vector2f(0.5f, 0.5f));
	restart->SetActive(false);

	auto* exit = AddGo(new SpriteGo("graphics/out.png", "ExitButton"));
	exit->SetOrigin(Origins::MC);
	exit->SetPosition({ window.getSize().x * 0.5f, window.getSize().y * 0.7f });
	exit->SetScale(sf::Vector2f(0.5f, 0.5f));
	exit->SetActive(false);
	Scene::Init(window);
}

void SceneBattle::Enter()
{
	DECK_CTRL.reset();
	RES_MGR(sf::Texture).Load("graphics/Background.png");
	RES_MGR(sf::Texture).Load("graphics/Cost.png");
	RES_MGR(sf::Texture).Load("graphics/Ironclad.png");
	RES_MGR(sf::Texture).Load("graphics/Golem.png");
	RES_MGR(sf::Texture).Load("graphics/Bash.png");
	RES_MGR(sf::Texture).Load("graphics/Defend.png");
	RES_MGR(sf::Texture).Load("graphics/Inflame.png");
	RES_MGR(sf::Texture).Load("graphics/Strike.png");
	RES_MGR(sf::Texture).Load("graphics/Shield.png");
	RES_MGR(sf::Texture).Load("graphics/End.png");
	RES_MGR(sf::Texture).Load("graphics/Deck.png");
	RES_MGR(sf::Texture).Load("graphics/Grave.png");
	RES_MGR(sf::Texture).Load("graphics/Buf.png");
	RES_MGR(sf::Texture).Load("graphics/Debuf.png");
	RES_MGR(sf::Texture).Load("graphics/Slash.png");
	RES_MGR(sf::Texture).Load("graphics/Aura.png");
	RES_MGR(sf::Texture).Load("graphics/Restart.png");
	RES_MGR(sf::Texture).Load("graphics/out.png");
	RES_MGR(sf::Font).Load("fonts/Sansation.ttf");
	for (int i = 0; i < 5; i++) {
		auto tempCard = (Card*)FindGo("Card" + std::to_string(i));
		tempCard->SetActive(true);
	}
	Animation::Instance().Init();
	
	Scene::Enter();
}

void SceneBattle::Exit()
{
	RES_MGR(sf::Texture).UnLoad("graphics/Background.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Cost.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Ironclad.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Golem.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Bash.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Defend.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Inflame.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Strike.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Shield.png");
	RES_MGR(sf::Texture).UnLoad("graphics/End.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Deck.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Grave.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Buf.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Debuf.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Slash.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Aura.png");
	RES_MGR(sf::Texture).UnLoad("graphics/Restart.png");
	RES_MGR(sf::Texture).UnLoad("graphics/out.png");
	RES_MGR(sf::Font).UnLoad("fonts/Sansation.ttf");
}



void SceneBattle::Update(float dt)
{
	Animation::Instance().Update(dt);
	auto pobj = FindGo("Player");
	auto player = (Player*)pobj;
	auto eobj = FindGo("Golem");
	auto enemy = (Enemy*)eobj;
	auto bobj = FindGo("EndButton");
	auto endButton = (SpriteGo*)bobj;
	std::deque<Card*> card_list;
	for (int i = 0; i < 5; i++) {
		auto tempCard = (Card*)FindGo("Card" + std::to_string(i));
		tempCard->UpdateCard(player->GetAtk());
		card_list.push_back(tempCard);
	}
	//입력대기 / 플레이어턴 진행 / 적 턴 진행 / 적 행동결정
	switch (turn) {
		case Turn::CardSelect: {
			if (InputManager::GetBtnPressed(sf::Mouse::Left)) {
				if(endButton->CheckPos(InputManager::GetMousePosWindow(window))){
					turn = Turn::DiscardCard;
				}
				if (player->GetCost() > 0) {
					int i = 0;
					for (auto it : card_list) {
						if (it->CheckPos(InputManager::GetMousePosWindow(window)) && it->IsActive()) {
							if (it->getType() == Cards::Bash && player->GetCost() < 2)
								break;
							it->selected();
							selectedCard = i;
							turn = Turn::MonsterSelect;
							break;
						}
						i++;
					}

				}
			}
			break;
		}
		case Turn::MonsterSelect: {
			if (InputManager::GetBtnPressed(sf::Mouse::Left)) {
				Card* pressedCard;
				if (endButton->CheckPos(InputManager::GetMousePosWindow(window))) {
					turn = Turn::DiscardCard;
				}
				auto card = (Card*)FindGo("Card" + std::to_string(selectedCard));
				if (card->getType() != Cards::Bash && card->getType() != Cards::Strike) {
					if (player->CheckPos(InputManager::GetMousePosWindow(window)))
					{
						PlayerAction(*player, *enemy, *card);
						card->unSelected();
						player->UseCost(card->getType());
						card->SetActive(false);
						DECK_CTRL.useCard(1);
						turn = Turn::CardSelect;
					}
					else if ((pressedCard = checkCardClick(card_list, InputManager::GetMousePosWindow(window))) != nullptr) {
						if (!(pressedCard->getType() == Cards::Bash && player->GetCost() < 2)) {
							if (!(pressedCard == card)) {
								pressedCard->selected();
								card->unSelected();
								selectedCard = (int)*(pressedCard->GetName().end() - 1) - 48;
								turn = Turn::MonsterSelect;
							}
							else {
								card->unSelected();
								selectedCard = 0;
								turn = Turn::CardSelect;
							}

						}
					}
					else {
						card->unSelected();
						selectedCard = -1;
						turn = Turn::CardSelect;
					}
				}
				else if (enemy->CheckPos(InputManager::GetMousePosWindow(window)))
				{
					PlayerAction(*player, *enemy, *card);
					card->unSelected();
					player->UseCost(card->getType());
					card->SetActive(false);
					DECK_CTRL.useCard(1);
					turn = Turn::CardSelect;
				}
				else if ((pressedCard = checkCardClick(card_list, InputManager::GetMousePosWindow(window)))!=nullptr) {
					if (!(pressedCard->getType() == Cards::Bash && player->GetCost() < 2)) {
						if (!(pressedCard == card)) {
							pressedCard->selected();
							card->unSelected();
							selectedCard = (int)*(pressedCard->GetName().end() - 1) - 48;
							turn = Turn::MonsterSelect;
						}
						else {
							card->unSelected();
							selectedCard = 0;
							turn = Turn::CardSelect;
						}
					
					}	
				}
				else{
					card->unSelected();
					selectedCard = -1;
					turn = Turn::CardSelect;
				}

			}
			break;
		}
		case Turn::DiscardCard:{
			if (elapsedTime == 0) {
				for (auto it : card_list) {
					if (it->IsActive()) {
						DECK_CTRL.useCard(1);
					}
				}
			}
			elapsedTime += dt;
			if (elapsedTime < 0.7) {
				for (auto it : card_list) {
					sf::Vector2f temp = it->GetPosition();
					temp += sf::Vector2f(0.f, cardVelocity * dt);
					it->SetPosition(temp);
				}
			}
			else {
				elapsedTime = 0;
				turn = Turn::MonsterTurn;
			}
			break;
		}
		case Turn::MonsterTurn: {
			if (rand() % 2) {
				player->Hit(enemy->GetAtk());
				Animation::Instance().triggerMAttack();
			} else{
				enemy->ChargeShield(10);
			}
			enemy->DecreaseVulnerable();
			turn = Turn::RestoreCard;
			break;
		}
		case Turn::RestoreCard: {
			for (auto it : card_list) {
				it->Reset();
				it->SetActive(true);
			}
			turn = Turn::DrawCard;
			break;
		}
		case Turn::DrawCard: {
			elapsedTime += dt;
			if (elapsedTime < 0.7) {
				for (auto it : card_list) {
					sf::Vector2f temp = it->GetPosition();
					temp -= sf::Vector2f(0.f, cardVelocity * dt);
					if (temp.y < window->getSize().y * 0.3f) {
						temp.y = window->getSize().y * 0.3f;
						elapsedTime = 1;
					}
					it->SetPosition(temp);
				
				}
			}else {
				elapsedTime = 0;
				player->RestoreCost();
				turn = Turn::CardSelect;
			}
			break;
		}
		case Turn::Victory: {
			if (InputManager::GetBtnPressed(sf::Mouse::Left)) {
				auto it1 = (SpriteGo*)FindGo("RestartButton");
				auto it2 = (SpriteGo*)FindGo("ExitButton");
				auto it3 = (TextGo*)FindGo("VICTORY");
				if (it1->CheckPos(InputManager::GetMousePosWindow(window)))
				{
					it1->SetActive(false);
					it2->SetActive(false);
					it3->SetActive(false);
					Enter();
					turn = Turn::CardSelect;
				}
				else if (it2->CheckPos(InputManager::GetMousePosWindow(window)))
				{
					it1->SetActive(false);
					it2->SetActive(false);
					it3->SetActive(false);
					Enter();
					turn = Turn::CardSelect;
					SCENE_MGR.ChangeScene(SceneIds::Dev2);
				}
			}
			break;
		}
		case Turn::Gameover: {
			if (InputManager::GetBtnPressed(sf::Mouse::Left)) {
				auto it1 = (SpriteGo*)FindGo("RestartButton");
				auto it2 = (SpriteGo*)FindGo("ExitButton");
				auto it3 = (TextGo*)FindGo("GAMEOVER");
				if (it1->CheckPos(InputManager::GetMousePosWindow(window)))
				{
					it1->SetActive(false);
					it2->SetActive(false);
					it3->SetActive(false);
					Enter();
					turn = Turn::CardSelect;
				}
				else if (it2->CheckPos(InputManager::GetMousePosWindow(window)))
				{
					it1->SetActive(false);
					it2->SetActive(false);
					it3->SetActive(false);
					Enter();
					turn = Turn::CardSelect;
					SCENE_MGR.ChangeScene(SceneIds::Dev2);
				}
				
			}
			break;

		}
	}
	if (player->GetHp() == 0) {
		auto it = (TextGo*)FindGo("GAMEOVER");
		it->SetActive(true);
		auto it2 = (SpriteGo*)FindGo("RestartButton");
		it2->SetActive(true);
		auto it3 = (SpriteGo*)FindGo("ExitButton");
		it3->SetActive(true);
		player->Heal(50);
		turn = Turn::Gameover;
	}
	else if (enemy->GetHp() == 0) {
		auto it1 = (TextGo*)FindGo("VICTORY");
		it1->SetActive(true);
		auto it2 = (SpriteGo*)FindGo("RestartButton");
		it2->SetActive(true);
		auto it3 = (SpriteGo*)FindGo("ExitButton");
		it3->SetActive(true);
		enemy->Heal(100);
		turn = Turn::Victory;
	}
	if (InputManager::GetKeyPressed(sf::Keyboard::Escape)) {
		auto it = (TextGo*)FindGo("GAMEOVER");
		it->SetActive(false);
		auto it2 = (SpriteGo*)FindGo("RestartButton");
		it2->SetActive(false);
		auto it3 = (SpriteGo*)FindGo("ExitButton");
		it3->SetActive(false);
		Enter();
		turn = Turn::CardSelect;
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
	Scene::Update(dt);
}

void SceneBattle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	Animation::Instance().Draw(window);
}

void SceneBattle::PlayerAction(Player& player, Enemy& enemy, Card& card)
{
	int atk = player.GetAtk();
	if (enemy.GetVulnerable()) {
		atk = (int)(atk * 1.5f);
	}
	switch (card.getType()) {
		case Cards::Bash: {
			enemy.Hit(8 + atk);
			enemy.HitVulnerable(2);
			Animation::Instance().triggerAttack();
			break;
		}
		case Cards::Defend: {
			player.GetShield(5);
			break;
		}
		case Cards::Inflame: {
			player.BufAtk(2);
			Animation::Instance().triggerBuf();
			break;
		}
		case Cards::Strike: {
			enemy.Hit(6 + atk);
			Animation::Instance().triggerAttack();
			break;
		}
	}
}

Card* SceneBattle::checkCardClick(std::deque<Card*> list, sf::Vector2f pos)
{
	for (auto it : list) {
		if (it->CheckPos(pos)) {
			return it;
		}
	}
	return nullptr;
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