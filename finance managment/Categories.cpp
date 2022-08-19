#include "categories.h"

std::string Categories::getCategory(int category)
{
    switch (category)
    {
    case CASH: return "Cash";
    case UTILITYBILLS: return "Utility bills";
    case CREDITS: return "Credits";
    case FOOD: return "Food";
    case AUTOMOBILE: return "Automobile";
    case ENTERTEIMENTS: return "Enterteiments";
    case EDUCATION: return "Education";
    case CLOTHES: return "Clothes";
    case RESTAURANTS: return "Restaurants";
    case PRESENTS: return "Presents";
    case HOBBY: return "Hobby";
    case APPLIANCES: return "Appliances";
    case OTHER: return "Other";
    }
}
