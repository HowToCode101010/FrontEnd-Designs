const taskInput = document.getElementById('taskInput');
const addBtn = document.getElementById('addBtn');
let tasks = [];
addBtn.addEventListener('click', addTask);
function addTask(){
    const TaskText = taskInput.value.trim();   
    if(TaskText === '')
        {
            alert("Please Enter a task!");
            return;
        } 
    const newTask = {
        id:Date.now(),
        text: TaskText,
        completed: false
    }     
    tasks.push(newTask);
    taskInput.value = '';
    saveTasks();
    renderTasks();
}