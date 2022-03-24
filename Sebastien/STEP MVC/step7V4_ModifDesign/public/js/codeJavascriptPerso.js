const ctx = document.getElementById('myChart').getContext('2d');
const myChart = new Chart(ctx, {
    type: 'line',
    data:{
        labels: lesDates,
        datasets:
            [{
            data: lesMesures,
            lineTension: 0,
            BackgroundColor: 'transparent',
            borderColor:'#007bff',
            borderwidth: 4,
            pointBackgroundColor: '#007bff'
            }]
        },
        options:
        {
            scales:{
            yAxes:
            [{
                ticks: {
                beginAtZero: false
                }
            }]
        },
        legend:
        {
            display: false
        }
    }
});