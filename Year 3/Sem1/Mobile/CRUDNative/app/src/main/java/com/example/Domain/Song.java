package com.example.Domain;

import android.media.Image;

import java.io.Serializable;

public class Song implements Serializable {
    private String title;
    private String author;

    public Song(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String toString() {
        return this.author.toString() + " - " + this.title.toString();
    }
}
