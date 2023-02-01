function changeColor(){
    head.style.color = "red";
}

var clicked = 0;

window.onload = function(){
    let canvas = document.getElementById("pain");
    canvas.width = 800;
    canvas.height = 400;
    let context = canvas.getContext("2d");

    var x = 0;
    var y = 50;
    function draw(){
        context.clearRect(0, 0, 800, 400);
        context.beginPath();
        context.rect(x,y,50,50);
        context.fillStyle = "red";
        context.fill();
    }


    let btn = document.getElementById("trai");
    btn.onclick = function(){
        clicked++;
        x += 100;
        draw();
        context.beginPath();
        context.font = "30px Arial"
        context.fillStyle = "red"
        context.fillText("Count: " + clicked ,5,25);
    }

    context.beginPath();
    context.rect(x,y,50,50);
    context.fillStyle = "red";
    context.fill();

    // setInterval(draw,1000/144);


    

}