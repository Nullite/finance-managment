#include "Controller.h"

int main()
{
    srand(time(NULL));
    Controller controller = Controller::getInstance();
    
    controller.addCard(1);
    controller.addCard(2);
    controller.addCard(3);

    controller.addMoney(0, 1000);
    controller.addMoney(1, 500);
    controller.addMoney(2, 10000);
    controller.cardList();
    system("pause");
    system("cls");
    controller.cash(700, 0, 24022022);
    controller.cash(1500, 1, 1012022);
    controller.cash(3500, 1, 1012024);
    controller.cardList();
    controller.report(1012024, 1);
}
