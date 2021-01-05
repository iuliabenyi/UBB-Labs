package com.example.crudnative

import android.content.Context
import android.content.Intent
import android.content.Intent.getIntent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.*
import androidx.appcompat.app.AlertDialog
import com.example.Domain.Repository
import com.example.Domain.Song
import com.example.EditPage

class SongPage  : AppCompatActivity() {
    lateinit var editBtn : Button
    lateinit var deleteBtn : Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_song_page)
        var repo = intent.extras?.get("repo") as Repository
        var position = intent.extras?.get("position") as Int

        editBtn = findViewById(R.id.editBtn)
        deleteBtn = findViewById(R.id.deleteBtn)
        val titleView: TextView = findViewById(R.id.titleTv)
        val artistView: TextView = findViewById(R.id.artistTv)
        var song : Song = repo.getSong(position)
        titleView.text = song.title;
        artistView.text = song.author;

        editBtn.setOnClickListener{
            val editPage = Intent(applicationContext, EditPage::class.java)
            editPage.putExtra("repo", repo)
            editPage.putExtra("position", position)
            startActivity(editPage)
        }

        deleteBtn.setOnClickListener{

            System.out.println(repo.songs)
            val builder = AlertDialog.Builder(this@SongPage)
            builder.setTitle("Confirmation")
            builder.setMessage("Are you sure you want to delete this song?")
            builder.setPositiveButton("Yes"){dialog, which ->
                repo.deleteSong(song)
                finish()
            }
            builder.setNegativeButton("No"){dialog,which ->
                Toast.makeText(applicationContext,"Not deleting",Toast.LENGTH_SHORT).show()
                finish()
            }
            builder.setNeutralButton("Cancel"){_,_ ->
                Toast.makeText(applicationContext,"You cancelled the dialog.",Toast.LENGTH_SHORT).show()
                finish()
            }
            val dialog: AlertDialog = builder.create()
            dialog.show()

        }

        System.out.println(repo.songs)
    }

}
