
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int kub_brs() {
    srand(time(NULL));
    int dise;
    dise = rand()%6+1;
    return (dise);
}
int main()
{
    int vvod;
    int hod=0;
    int prop[2] = {0,0};
    int player_now = 0;
    int player_mon[2] = { 0,0 };
    int player_det[2] = { 0,0 };
    int player_stan[2] = { 0,0 };
    int player_poz[2] = { 0,0 };
    int stan_LV[16] = { 0,1,0,0,2,0,0,2,0,0,0,3,0,0,4,0 };
    setlocale(LC_ALL, "Russian");
    cout << "Вашему вниманию представленна полностью текстовая настольная игра Zavod, её правила очень просты:\nВы играете за обычного рабочего цель которого переработать план на 100 деталей и занять место начальника завода.\nИгровое поле представляет из себя замкнутый круг - Старт,станок LV1,токарь,банк,станок LV2,токарь,банк,станок LV2, перекур, токарь,банк,станок LV3,токарь,банк,станок LV4,пятница,старт.\n Каждый ход вы кидаете кубик и делаете ход, в зависимости от клетки на которой вы окажетесь вы можете совершить определённые действия игра заканчивается если 1 из игроков набрал 100 деталей или 1 из игроков потерял все свои детали\nВиды клеток:\nСтанок - на этой клетке вы можете вытачить детали или улучшить станок(каждый станок имеет уровень и приносит кол-во деталей равное уровню) \nТокарь - на этой клетке вы можете купить 5 деталей за 3 монеты\nБанк - здесь вы можете поменять 3 детали на 5 монет\nПерекур/Пятница - эти клетки идентичны и попав на них вы пропускаете ход и платите 5 деталей*1,5*на кол-во ходов\nКаждый круг вы получаете ЗП в размере 10 монет\nКаждый ход за 10 монет вы можете купить 1 личный станок который будет приносить 1 деталь за ход\n Приятной игры\n";
    while (1) {
        if (prop[player_now] == 0) {
            cout << "ход " << player_now + 1 << " игрока, кол-во монет = " << player_mon[player_now] << " кол-во деталей = " << player_det[player_now] << " кол-во станков = " << player_stan[player_now] << '\n';
            player_poz[player_now] += kub_brs();
            if (player_poz[player_now] > 15) {
                player_poz[player_now] = player_poz[player_now] % 16;
                player_mon[player_now] += 10;
            }
            cout << "Вы на клетке " << player_poz[player_now] + 1 << '\n';
            if (player_poz[player_now] == 0) {
                cout << "Вы на клетке старта, с окончанием выходных\n";
            }
            if (player_poz[player_now] == 1 || player_poz[player_now] == 4 || player_poz[player_now] == 7 || player_poz[player_now] == 11 || player_poz[player_now] == 14) {
                cout << "Вы на клетке станок. Хотите поработать или улучшите станок?(введите 1 или 2): ";
                cin >> vvod;
                if (vvod == 1) {
                    player_det[player_now] += stan_LV[player_poz[player_now]];
                    cout << "получено деталей: " << stan_LV[player_poz[player_now]] << '\n';
                }
                else {
                    stan_LV[player_poz[player_now]]++;
                    cout << "уровень станка: " << stan_LV[player_poz[player_now]] << '\n';
                }
            }if (player_poz[player_now] == 2 || player_poz[player_now] == 5 || player_poz[player_now] == 9 || player_poz[player_now] == 12) {
                cout << "Вы на клетке токарь.Хотите купит 5 деталей за 3 монеты? (введите 1 - да или 2 - нет) : ";
                if (vvod == 1) {
                    if (player_mon[player_now] >= 3) {
                        player_mon[player_now] -= 3;
                        player_det[player_now] += 5;
                        cout << "поздравляю с преобретением!\n";
                    }
                    else
                        cout << "не хватает монет\n";
                }
            }if (player_poz[player_now] == 3 || player_poz[player_now] == 6 || player_poz[player_now] == 10 || player_poz[player_now] == 13) {
                cout << "Вы на клетке Банк. Хотите продать 3 детали за 5 монет?(введите 1-да или 2-нет): ";
                cin >> vvod;
                if (vvod == 1) {
                    if (player_det[player_now] >= 3) {
                        player_det[player_now] -= 3;
                        player_mon[player_now] += 5;
                        cout << "поздравляю с продажей!\n";
                    }
                    else
                        cout << "не хватает монет\n";
                }
            }if (player_poz[player_now] == 8 || player_poz[player_now] == 15) {
                player_det[player_now] -= 5*1.5*hod;
                prop[player_now] = 1;
                if (player_poz[player_now] == 8) cout << "вы вышли на перекур и пропускаете 1 ход, так же сигареты вы выменяли на 5 деталей(-5 деталей)\n";
                else cout << "Пятница для вас как праздник, в пылу праздности вы потеряли 5 деталей(-5 деталей)\n";
            }
            cout << "Вы можете купит станок личный станок за 10 монет(1-да,2-нет)";
            cin >> vvod;
            if (vvod == 1) {
                if (player_mon[player_now] >= 10) {
                    player_mon[player_now] -= 10;
                    player_stan[player_now] ++;
                    cout << "поздравляю с преобретением!\n";
                }
                else
                    cout << "не хватает монет\n";
            }
        }
        else {
            prop[player_now] = 0;
        }
        player_det[player_now] += player_stan[player_now];
        if (player_det[player_now] >= 100) {
            cout << "Поздравляю игрок " << player_now + 1 << " победил! Для новой игры перезагрузитесь\n";
            break;
        }
        player_now++;
        if (player_now > 1)player_now = 0;
    }
}