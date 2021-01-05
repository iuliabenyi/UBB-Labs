package com.example.crudnative

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.ImageView
import android.widget.TextView
import com.example.Domain.Song

class MyListAdapter(
    var mCtx:Context, var resource:Int,
    var items: MutableList<Song>
)
    :ArrayAdapter<Song>( mCtx , resource , items ){
    override fun getView(position: Int, convertView: View?, parent: ViewGroup): View {
        val layoutInflater :LayoutInflater = LayoutInflater.from(mCtx)

        val view : View = layoutInflater.inflate(resource , null )
        val imageView :ImageView = view.findViewById(R.id.iconIv)
        var textView : TextView = view.findViewById(R.id.titleTv)
        var authorView : TextView = view.findViewById(R.id.authorTv)


        var song : Song = items[position]

        //imageView.setImageDrawable(mCtx.resources.getDrawable(song.photo))
        textView.text = song.title;
        authorView.text = song.author;


        return view
    }

}