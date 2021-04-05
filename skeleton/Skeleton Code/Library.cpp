#include "Library.h"

Library::~Library()
{ // TODO: according to header
}

void Library::addLibraryItem(LibraryItem *libraryItem)
{ // TODO: according to header
}

LibraryItem *Library::searchLibraryItemByExactName(string name) const
{ // TODO: according to header
}

LibraryItem *Library::searchLibraryItemByExactPublishedDate(int targetDate) const
{ // TODO: according to header
}

list<LibraryItem *> *Library::searchLibraryItemByPublishedDateRange(int startDate, int endDate) const
{ // TODO: according to header
}

bool Library::borrowItem(string name) const
{ // TODO: according to header
}

bool Library::returnItem(string name) const
{ // TODO: according to header
}
