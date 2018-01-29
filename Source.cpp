#include <allegro5\allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

using namespace std;

int main() {
	int year;
	cout << "what year is it?" << endl;
	cin >> year;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_SAMPLE *a = NULL;
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_audio();
	al_init_acodec_addon();

	display = al_create_display(1200, 1100);
	al_set_window_position(display, 400, 0);
	al_set_window_title(display, "Happy Dino Day!!!!!");
	al_reserve_samples(1);

	ALLEGRO_BITMAP *Dino = al_load_bitmap("img-34.jpg");
	ALLEGRO_FONT *Word = al_load_ttf_font("leadcoat.ttf", 72, 0);
	a = al_load_sample("yes-hahahaa.wav");

	al_clear_to_color(al_map_rgb(252, 252, 252));

	al_draw_bitmap(Dino, -200, 0, 0);
	al_draw_text(Word, al_map_rgb(200, 40, 200), 300, 50, ALLEGRO_ALIGN_CENTRE, "HAPPLY DINO DAY");
	al_draw_textf(Word, al_map_rgb(800, 200, 150), 800, 800, ALLEGRO_ALIGN_CENTRE, "AND HAPPPPLYYY %d", year);
	al_draw_rectangle(550, 50, 50, 120, al_map_rgb(600, 100, 200), 5);
	al_play_sample(a, 1.0, 0.0, 1.5, ALLEGRO_PLAYMODE_LOOP, NULL);

	al_flip_display();

	al_rest(10);
	al_destroy_display(display);
	al_destroy_sample(a);

	return 0;
}