const Library = [];

function Book(author, title, pages, read)
{
    this.id = crypto.randomUUID();
    this.author = author;
    this.title = title;
    this.pages = pages;
    this.read = read;
}

Book.prototype.toggleRead = function(){
    this.read = !this.read;
}

function addBooktoLibrary(author, title, pages, read)
{
    const newBook = new Book(author, title, pages, read);
    Library.push(newBook);
    displayBooks();
}
function displayBooks()
{
    const container = document.getElementById("booksContainer");
    container.innerHTML = "";

    Library.forEach(book => {
        const bookCard = document.createElement('div');
        bookCard.classList.add('book-Card');
        bookCard.dataset.id = book.id;

        bookCard.innerHTML = `<h3>${book.title}</h3>
      <p><strong>Author:</strong> ${book.author}</p>
      <p><strong>Pages:</strong> ${book.pages}</p>
      <p><strong>Read:</strong> ${book.read ? "Yes" : "No"}</p>
      <button class="toggle-read">Toggle Read Status</button>
      <button class="remove-book">Remove Book</button>`;
        bookCard.querySelector(".toggle-read").addEventListener('click', () => {
            book.toggleRead();
            displayBooks();
        })
        bookCard.querySelector(".remove-book").addEventListener('click', () => {
            removeBooks(book.id);
        })
        container.appendChild(bookCard);
    })
}
function removeBooks(id)
{
    const i = Library.findIndex(book => book.id === id)
    if(i !== -1)
    {
        Library.splice(i, 1);
        displayBooks();
    }
}
const newBook = document.getElementById('newBookBtn');
const dialog = document.getElementById('bookFormDialog');
const cancel = document.getElementById('cancelBtn');
const newBookForm = document.getElementById('newBookForm');
newBook.addEventListener('click', () => {
    dialog.showModal();
})
cancel.addEventListener('click', () => {
    dialog.close();
})
newBookForm.addEventListener('submit', (event) => {
    event.preventDefault();

    const formData = new FormData(newBookForm);
    const title = formData.get('title').trim();
    const author = formData.get('author').trim();
    const pages = Number(formData.get('pages'));
    const read = formData.get("read") === "on";

    if(title && author && pages > 0)
    {
        addBooktoLibrary(author, title, pages, read);
        newBookForm.reset();
        dialog.close();
    }
    else{
        alert("Please fill out all details correctly.")
    }
})
