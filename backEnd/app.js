const express = require("express");

const app = express();

const drinks = [];

app.get("/", (req, res) => {
  return res.send("<h1>Hello World</h1> ");
});

app.get("/orders/drinks", (req, res) => {
  return res.json({
    drinks,
  });
});

app.post("/orders/drinks", (req, res) => {
  const drink = req.body.drink;

  drinks.push(drink);

  return res.json({
    drink,
  });
});

app.delete("/orders/drinks/{drink_id}", (req, res) => {
  const drink = req.params.drink_id;

  // Delete drink logic
  return res.send();
});
app.listen(3000);
