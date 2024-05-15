document.addEventListener("DOMContentLoaded", function () {
    // Function to handle applying filters
    function applyFilters() {
        // Logic to fetch selected filters and apply them
        // For demonstration purposes, let's just log the selected filters
        const selectedCategories = document.querySelectorAll('input[name="category"]:checked');
        const selectedLanguages = document.querySelectorAll('input[name="language"]:checked');
        const selectedTime = document.querySelector('input[name="time"]:checked');

        console.log("Selected Categories:");
        selectedCategories.forEach(category => console.log(category.value));
        
        console.log("Selected Languages:");
        selectedLanguages.forEach(language => console.log(language.value));

        console.log("Selected Time:");
        if (selectedTime) {
            console.log(selectedTime.value);
        } else {
            console.log("No time selected");
        }

        // Additional logic to filter movies based on selected filters
    }

    // Function to handle booking tickets
    function bookTickets() {
    // Logic to book tickets for the selected movie
        // For demonstration purposes, let's just log a message
        console.log("Tickets booked!");
    }

    // Event listeners for buttons
    document.querySelector('.btn-apply-filters').addEventListener('click', applyFilters);

    const bookButtons = document.querySelectorAll('.btn-book-ticket');
    bookButtons.forEach(button => button.addEventListener('click', bookTickets));
});
