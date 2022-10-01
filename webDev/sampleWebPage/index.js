function refreshTime() {
    const timeDisplay = document.querySelector(".time-span");
    const dateString = new Date().toLocaleString();
    const formattedString = dateString.replace(", ", " - ");
    timeDisplay.textContent = formattedString;
}
refreshTime();
setInterval(refreshTime, 1000);