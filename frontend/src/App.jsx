import { useState } from "react";

import "./App.css";

import { DrinkBuilderProvider, DrinkListProvider } from "./context";
import { DrinkBuilderView } from "./views/DrinkBuilder";
import { DrinkListView } from "./views/DrinkList";

function App() {
  const params = new Proxy(new URLSearchParams(window.location.search), {
    get: (searchParams, prop) => searchParams.get(prop),
  });

  const view = params.user ?? "customer";

  if (view === "customer") {
    return (
      <DrinkBuilderProvider>
        <DrinkBuilderView />
      </DrinkBuilderProvider>
    );
  } else {
    return (
      <DrinkListProvider>
        <DrinkListView />
      </DrinkListProvider>
    );
  }
}

export default App;
