function getRandomDrink(){
 
    let url = "https://www.thecocktaildb.com/api/json/v1/1/random.php"
    fetch(url)
        .then(res => res.json()) // parse response as JSON
        .then(data => {
            console.log(data.drinks);
            let cocktailName = data.drinks[0].strDrink;
            // console.log(cocktailName);
            document.getElementById('cocktailName').innerText = cocktailName;
            let cocktailImgSrc = data.drinks[0].strDrinkThumb
            document.getElementById('cocktailImg').setAttribute('src', cocktailImgSrc);
        })
        .catch(err => {
            console.log(`error ${err}`)
        });
}
getRandomDrink();