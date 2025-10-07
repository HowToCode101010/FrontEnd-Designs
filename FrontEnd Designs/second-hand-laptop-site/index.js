let btnEL = document.getElementById("btn");
let txtEl = document.getElementById('text');
function changeText(){
    txtEl.innerText = "?????";
}
btnEL.addEventListener('hover', changeText);