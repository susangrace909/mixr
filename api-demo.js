function getRandomDrink(){
 
    let url = "https://www.thecocktaildb.com/api/json/v1/1/random.php"
    fetch(url)
        .then(res => res.json()) // parse response as JSON
        .then(data => {
            console.log(data.drinks);
        })
        .catch(err => {
            console.log(`error ${err}`)
        });
}
getRandomDrink();