import React, {useState, useEffect} from "react";
//import {useMachine} from 'xstate';
import getRandomDrink from "../api-demo";

const max_drinks = 20;

export const DrinkListView = () => {
  let data = getRandomDrink();
  let cocktailName = data.drinks[0].strDrink;
  let cocktailImgSrc = data.drinks[0].strDrinkThumb;
  let ingredients = Object.entries(data.drinks[0]).filter(x => x[0].includes('Ingredient'));
  ingredients = ingredients.filter(x => x[1]);
  let ingredientsArr = ingredients.map(x => x[1]);

  // function onlyUniques(value, index, self){
  //   return self.indexOf(value === index);
  // }

  // for (let i = 0; i < max_drinks; i++) {
  //   let drink = getRandomDrink()
  //     .then(drink => drinksArr.push(getRandomDrink()))
    
  // }

  // drinksArr.filter(onlyUniques);
  console.log(drink, cocktailName, cocktailImgSrc, ingredientsArr);

};
