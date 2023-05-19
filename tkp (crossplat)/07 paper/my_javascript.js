$(document).ready(function() {
    paper.install(window);
    paper.setup("myCanvas");

    var canvas_width = $("#myCanvas").width();
    var canvas_height = $("#myCanvas").height();
    var r = 20;
    var x = Math.floor(Math.random()*(canvas_width-r))+r;
    var y = Math.floor(Math.random() * (canvas_height - r)) + r;
    
    // закомментировала, потому что не нравился появляющийся при запуске кружок в случайном месте
    // var myCircle = new paper.Path.Circle(new Point(x, y), r);
    // myCircle.strokeColor = "black";
    // myCircle.strokeWidth = 1;
    // view.draw();

    $("#draw").click(function() {
        var x = parseInt($("#x").val());
        var y = parseInt($("#y").val());
        var r = parseInt($("#r").val());

        if (x>=(0+r) && x<= (canvas_width-r) && y >=(0+r) && y<=(canvas_height-r) && r >0 ) {
            var myCircle = new paper.Path.Circle(new Point(x, y), r);
            // получение цветов и толщины обводки из документа
            myCircle.strokeColor = $("#stroke").val();
            myCircle.strokeWidth = $("#width").val();
            myCircle.fillColor = $("#fill").val();
            view.draw();
        }
    });

    $("#clean").click(function() {
        paper.project.clear();
        view.draw();
    });

    $("#generator").click(function() {
        paper.project.clear();

        for(var i=0; i<10; i++) {
            var x = Math.floor(Math.random()*(canvas_width-r))+r;
            var y = Math.floor(Math.random()*(canvas_height-r))+r;
            var myCircle = new paper.Path.Circle(new Point(x, y), r);
            myCircle.strokeColor = "black";
            myCircle.strokeWidth = 1;
            // случайный цвет заливки
            myCircle.fillColor = "#" + Math.floor(Math.random()*16777215).toString(16)
        }
        view.draw();
    });
});
