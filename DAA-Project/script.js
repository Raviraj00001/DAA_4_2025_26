const N = 8;
let maze = [];
let rat = {x:0, y:0};
let time = 0;
let score = 0;
let timer;

// 🔹 Generate Random Maze
function generateMaze() {
    maze = [];
    for (let i = 0; i < N; i++) {
        let row = [];
        for (let j = 0; j < N; j++) {
            row.push(Math.random() > 0.3 ? 1 : 0);
        }
        maze.push(row);
    }

    maze[0][0] = 1;
    maze[N-1][N-1] = 1;

    rat = {x:0, y:0};
    time = 0;

    clearInterval(timer);
    timer = setInterval(() => {
        time++;
        document.getElementById("time").innerText = time;
    }, 1000);

    drawMaze();
}

// 🔹 Draw Maze
function drawMaze(extra = []) {
    const mazeDiv = document.getElementById("maze");
    mazeDiv.innerHTML = "";

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            let cell = document.createElement("div");
            cell.classList.add("cell");

            if (maze[i][j] === 0) cell.classList.add("wall");
            else cell.classList.add("path");

            // visited
            if (extra.some(p => p.x === i && p.y === j)) {
                cell.classList.add("visited");
            }

            // rat
            if (i === rat.x && j === rat.y) {
                cell.classList.add("rat");
                cell.innerHTML = "🐭";
            }

            // goal
            if (i === N-1 && j === N-1) {
                cell.classList.add("goal");
                cell.innerHTML = "🏁";
            }

            mazeDiv.appendChild(cell);
        }
    }
}

// 🔹 Move Rat
function move(dir) {
    let x = rat.x;
    let y = rat.y;

    if (dir === "up") x--;
    if (dir === "down") x++;
    if (dir === "left") y--;
    if (dir === "right") y++;

    if (isValid(x,y)) {
        rat = {x,y};
        score += 5;

        if (x === N-1 && y === N-1) {
            document.getElementById("msg").innerText = "🎉 You Win!";
            clearInterval(timer);
        }
    } else {
        document.getElementById("msg").innerText = "❌ Blocked!";
        score -= 2;
    }

    document.getElementById("score").innerText = score;
    drawMaze();
}

// 🔹 Valid Check
function isValid(x,y) {
    return x>=0 && y>=0 && x<N && y<N && maze[x][y] === 1;
}

// 🔥 Auto Solve (Backtracking)
async function autoSolve() {
    let visited = Array.from({length:N}, () => Array(N).fill(false));
    await solve(0,0,visited);
}

async function solve(x,y,visited) {
    if (!isValid(x,y) || visited[x][y]) return false;

    visited[x][y] = true;
    rat = {x,y};
    drawMaze([{x,y}]);

    await sleep(200);

    if (x === N-1 && y === N-1) return true;

    if (await solve(x+1,y,visited)) return true;
    if (await solve(x,y+1,visited)) return true;
    if (await solve(x-1,y,visited)) return true;
    if (await solve(x,y-1,visited)) return true;

    return false;
}

// 🎯 BFS Shortest Path
function shortestPath() {
    let queue = [[0,0,[]]];
    let visited = Array.from({length:N}, () => Array(N).fill(false));

    while (queue.length) {
        let [x,y,path] = queue.shift();

        if (!isValid(x,y) || visited[x][y]) continue;

        path.push({x,y});
        visited[x][y] = true;

        if (x === N-1 && y === N-1) {
            drawShortest(path);
            return;
        }

        queue.push([x+1,y,[...path]]);
        queue.push([x,y+1,[...path]]);
        queue.push([x-1,y,[...path]]);
        queue.push([x,y-1,[...path]]);
    }
}

// highlight shortest
function drawShortest(path) {
    const mazeDiv = document.getElementById("maze");
    const cells = mazeDiv.children;

    path.forEach(p => {
        let index = p.x * N + p.y;
        cells[index].classList.add("shortest");
    });
}

// delay
function sleep(ms) {
    return new Promise(res => setTimeout(res, ms));
}

// keyboard
document.addEventListener("keydown", e => {
    if (e.key === "ArrowUp") move("up");
    if (e.key === "ArrowDown") move("down");
    if (e.key === "ArrowLeft") move("left");
    if (e.key === "ArrowRight") move("right");
});

// start
generateMaze();