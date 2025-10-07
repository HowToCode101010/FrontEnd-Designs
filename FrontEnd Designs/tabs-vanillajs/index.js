const tabs = document.querySelector(".tabs");
const btns = document.querySelectorAll(".button");
const articles = document.querySelectorAll(".content");
tabs.addEventListener("click", function(e){
    const id = e.target.dataset.id;
    console.log(id);
    if(id) {
        btns.forEach(function(btn){
            btn.classList.remove
        })
    }
})