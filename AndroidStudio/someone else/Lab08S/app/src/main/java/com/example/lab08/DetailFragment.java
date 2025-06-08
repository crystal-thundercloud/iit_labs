package com.example.lab08;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

public class DetailFragment extends Fragment {

    String[] descrs = {
            "Treecko - Wood Gecko Pokémon. It makes its nest in a giant tree in the forest. It ferociously guards against anything nearing its territory. It is said to be the protector of the forest's trees.",
            "Grovyle - Wood Gecko Pokémon. Leaves grow out of this Pokémon's body. They help obscure a Grovyle from the eyes of its enemies while it is in a thickly overgrown forest.",
            "Sceptile - Forest Pokémon. In the jungle, its power is without equal. This Pokémon carefully grows trees and plants. It regulates its body temperature by basking in sunlight.",
            "Torchic - Chick Pokémon. If attacked, it strikes back by spitting balls of fire it forms in its stomach. A Torchic dislikes darkness because it can't see its surroundings.",
            "Combusken - Young Fowl Pokémon. It lashes out with 10 kicks per second. Its strong fighting instinct compels it to keep up its offensive until the opponent gives up.",
            "Blaziken - Blaze Pokémon. It learns martial arts that use punches and kicks. Every several years, its old feathers burn off, and new, supple feathers grow back in their place.",
            "Mudkip - Mud Fish Pokémon. On land, it can powerfully lift large boulders by planting its four feet and heaving. It sleeps by burying itself in soil at the water's edge.",
            "Marshtomp - Mud Fish Pokémon. Its toughened hind legs enable it to stand upright. Because it weakens if its skin dries out, it replenishes fluids by playing in mud.",
            "Swampert - Mud Fish Pokémon. If it senses the approach of a storm and a tidal wave, it protects its seaside nest by piling up boulders. It swims as fast as a jet ski."
    };

    int[] pics = {
            R.drawable.treecko,
            R.drawable.grovyle,
            R.drawable.sceptile,
            R.drawable.torchic,
            R.drawable.combusken,
            R.drawable.blaziken,
            R.drawable.mudkip,
            R.drawable.marshtomp,
            R.drawable.swampert
    };

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_detail, container, false);
    }
    public void setSelectedItem(String selectedItem) {
        TextView desc = getView().findViewById(R.id.detailsText);
        ImageView photo = getView().findViewById(R.id.photo);

        desc.setText(descrs[Integer.parseInt(selectedItem)]);
        photo.setImageResource(pics[Integer.parseInt(selectedItem)]);
    }
}
