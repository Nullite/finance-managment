#include "Controller.h"

int main()
{
    srand(time(NULL));
    Controller controller = Controller::getInstance();
    
    /*controller.addCard(1);
    controller.addCard(2);
    controller.addCard(3);

    controller.addMoney(0, 100000);
    controller.addMoney(1, 500);
    controller.addMoney(2, 10000);
    controller.cardList();
    system("pause");
    system("cls");*/
  /*  controller.cash( 1700, 0, 1012022);
    controller.cash(1500, 1, 6012022);
    controller.cash(3500, 1, 8012022);
    controller.spend(133, 0, 2012022, 4);
    controller.spend(4500, 1, 2012022, 4);
    controller.spend(1, 2, 2012022, 4);*/
    controller.cardList();
    /*controller.report(1012022, 3);
    controller.spendsRaiting(1012022, 1);
    controller.categoriesList();
    controller.saveExpences();
    controller.saveCards();*/
}
