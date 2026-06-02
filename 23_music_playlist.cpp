// music_playlist.cpp
#include <iostream>
#include <string>
using namespace std;

struct Song {
    int songId;
    string title;
    string artist;
    Song* next;
};

class Playlist {
private:
    Song* head;

public:
    Playlist() {
        head = NULL;
    }

    void addSong(int id, string title, string artist) {
        Song* newSong = new Song;
        newSong->songId = id;
        newSong->title = title;
        newSong->artist = artist;
        newSong->next = NULL;

        if (head == NULL) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        cout << "Added song: " << title << " by " << artist << endl;
    }

    void displayPlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        cout << "\nMusic Playlist:" << endl;
        Song* temp = head;
        int position = 1;
        while (temp != NULL) {
            cout << position++ << ". ID: " << temp->songId
                 << " - " << temp->title << " by " << temp->artist << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong(1, "Bohemian Rhapsody", "Queen");
    myPlaylist.addSong(2, "Imagine", "John Lennon");
    myPlaylist.addSong(3, "Hotel California", "Eagles");
    myPlaylist.addSong(4, "Hey Jude", "The Beatles");

    myPlaylist.displayPlaylist();

    return 0;
}
