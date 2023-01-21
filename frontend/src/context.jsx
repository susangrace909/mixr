import React, { createContext } from "react";
import { useInterpret } from "@xstate/react";
import { drink_builder_machine, drink_list_machine } from "./machines";

export const DrinkBuilderContext = createContext({});

export const DrinkListContext = createContext({});

export const DrinkBuilderProvider = (props) => {
  const drink_builder_service = useInterpret(drink_builder_machine);

  return (
    <DrinkBuilderContext.Provider value={{ drink_builder_service }}>
      {props.children}
    </DrinkBuilderContext.Provider>
  );
};

export const DrinkListProvider = (props) => {
  const drink_list_service = useInterpret(drink_list_machine);

  return (
    <DrinkListContext.Provider value={{ drink_list_service }}>
      {props.children}
    </DrinkListContext.Provider>
  );
};
