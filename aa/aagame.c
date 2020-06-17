#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>

struct coordinates
{
	int xCoordinate;
	int yCoordinate;
	int ballposition;
	int dotx;
	int doty;
};

int main() {
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_TIMER* timer;

	int firstDotX = 325, firstDotY = 155, secondDotX = 560, secondDotY = 170, thirdDotX = 545, thirdDotY = 425, fourthDotX = 310, fourthDotY = 410;
	int firstDotPosition = 2, secondDotPosition = 4, thirdDotPosition = 6, fourthDotPosition = 8;
	int ballNumber = 12;
	int ballthrowcounter = -1;
	int ballnumbercounter = 0;
	int finish = 0, win = 0, lose = 0;
	int finalBallNumber = 5;

	struct coordinates firstBall, secondBall, thirdBall, fourthBall, ball[5];

	al_init();
	al_install_keyboard();

	display = al_create_display(900, 900);
	timer = al_create_timer(1.0 / 30);
	queue = al_create_event_queue();
	al_start_timer(timer);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	//LOADING FONTS
	ALLEGRO_FONT* font = al_load_ttf_font("Roboto.ttf", 24, 0);
	ALLEGRO_FONT* infoFont = al_load_ttf_font("Light.ttf", 20, 0);
	ALLEGRO_FONT* endFont = al_load_ttf_font("Roboto.ttf", 80, 0);

	//LOADING SOUND EFFECTS
	ALLEGRO_SAMPLE* soundeffect = al_load_sample("soundEffect.mp3");
	ALLEGRO_SAMPLE* gameOver = al_load_sample("gameOver.mp3");
	ALLEGRO_SAMPLE* buzzSound = al_load_sample("buzzSound.mp3");
	ALLEGRO_SAMPLE* winSound = al_load_sample("winSound.mp3");
	ALLEGRO_SAMPLE* clapSound = al_load_sample("clapSound.mp3");

	al_reserve_samples(5);

	while (true) {

		al_draw_textf(infoFont, al_map_rgb(166, 166, 166), 20, 850, 0, "Press upper key to send the ball. ");

		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
			al_destroy_display(display);
			break;
		}

		//CIRCULAR MOTION FOR THE FIRST MAIN BALL
		if (firstDotPosition == 1) { //255, 280
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX += 5;
			firstDotY -= 10;

			if (firstDotY == 160)
				firstDotPosition = 2;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;

		}
		if (firstDotPosition == 2) { //325,155
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX += 10;
			firstDotY -= 5;

			if (firstDotY == 100)
				firstDotPosition = 3;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;

		}
		if (firstDotPosition == 3) { //445, 105
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX += 10;
			firstDotY += 5;

			if (firstDotY == 160)
				firstDotPosition = 4;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;

		}
		if (firstDotPosition == 4) { //560,170
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX += 5;
			firstDotY += 10;

			if (firstDotY == 290)
				firstDotPosition = 5;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;

		}
		if (firstDotPosition == 5) { //615, 300
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX -= 5;
			firstDotY += 10;

			if (firstDotY == 420)
				firstDotPosition = 6;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;

		}
		if (firstDotPosition == 6) { //545, 425
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX -= 10;
			firstDotY += 5;

			if (firstDotY == 480)
				firstDotPosition = 7;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;

		}
		if (firstDotPosition == 7) { //425, 475
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX -= 10;
			firstDotY -= 5;

			if (firstDotY == 420)
				firstDotPosition = 8;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;
		}
		if (firstDotPosition == 8) { //310, 410
			al_draw_filled_circle(440, 290, 200, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(firstDotX, firstDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, firstDotX, firstDotY, al_map_rgb(255, 255, 255), 2);

			firstDotX -= 5;
			firstDotY -= 10;

			if (firstDotY == 290)
				firstDotPosition = 1;

			firstBall.xCoordinate = firstDotX;
			firstBall.yCoordinate = firstDotY;
		}

		//CIRCULAR MOTION FOR THE SECOND MAIN BALL
		if (secondDotPosition == 1) { //250, 290
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX += 5;
			secondDotY -= 10;

			if (secondDotY == 160)
				secondDotPosition = 2;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;

		}
		if (secondDotPosition == 2) { //325, 155
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX += 10;
			secondDotY -= 5;

			if (secondDotY == 100)
				secondDotPosition = 3;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;

		}
		if (secondDotPosition == 3) { //445, 105
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX += 10;
			secondDotY += 5;

			if (secondDotY == 160)
				secondDotPosition = 4;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;

		}
		if (secondDotPosition == 4) { //560, 170
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX += 5;
			secondDotY += 10;

			if (secondDotY == 290)
				secondDotPosition = 5;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;

		}
		if (secondDotPosition == 5) { //615, 300
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX -= 5;
			secondDotY += 10;

			if (secondDotY == 420)
				secondDotPosition = 6;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;

		}
		if (secondDotPosition == 6) { //545, 425
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX -= 10;
			secondDotY += 5;

			if (secondDotY == 480)
				secondDotPosition = 7;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;

		}
		if (secondDotPosition == 7) { //425, 475
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX -= 10;
			secondDotY -= 5;

			if (secondDotY == 420)
				secondDotPosition = 8;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;
		}
		if (secondDotPosition == 8) { //310, 410
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(secondDotX, secondDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, secondDotX, secondDotY, al_map_rgb(255, 255, 255), 2);

			secondDotX -= 5;
			secondDotY -= 10;

			if (secondDotY == 290)
				secondDotPosition = 1;

			secondBall.xCoordinate = secondDotX;
			secondBall.yCoordinate = secondDotY;
		}

		//CIRCULAR MOTION FOR THE THIRD MAIN BALL
		if (thirdDotPosition == 1) { //255, 290
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX += 5;
			thirdDotY -= 10;

			if (thirdDotY == 160)
				thirdDotPosition = 2;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;

		}
		if (thirdDotPosition == 2) { //325, 155
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX += 10;
			thirdDotY -= 5;

			if (thirdDotY == 100)
				thirdDotPosition = 3;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;

		}
		if (thirdDotPosition == 3) { //445, 105
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX += 10;
			thirdDotY += 5;

			if (thirdDotY == 160)
				thirdDotPosition = 4;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;

		}
		if (thirdDotPosition == 4) { //560, 170
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX += 5;
			thirdDotY += 10;

			if (thirdDotY == 290)
				thirdDotPosition = 5;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;

		}
		if (thirdDotPosition == 5) { //615, 300
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX -= 5;
			thirdDotY += 10;

			if (thirdDotY == 420)
				thirdDotPosition = 6;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;

		}
		if (thirdDotPosition == 6) { //545, 425
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX -= 10;
			thirdDotY += 5;

			if (thirdDotY == 480)
				thirdDotPosition = 7;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;

		}
		if (thirdDotPosition == 7) { //425, 475
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX -= 10;
			thirdDotY -= 5;

			if (thirdDotY == 420)
				thirdDotPosition = 8;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;
		}
		if (thirdDotPosition == 8) { //310, 410
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(thirdDotX, thirdDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, thirdDotX, thirdDotY, al_map_rgb(255, 255, 255), 2);

			thirdDotX -= 5;
			thirdDotY -= 10;

			if (thirdDotY == 290)
				thirdDotPosition = 1;

			thirdBall.xCoordinate = thirdDotX;
			thirdBall.yCoordinate = thirdDotY;
		}

		//CIRCULAR MOTION FOR THE FOURTH MAIN BALL
		if (fourthDotPosition == 1) { //250, 290
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX += 5;
			fourthDotY -= 10;

			if (fourthDotY == 160)
				fourthDotPosition = 2;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;

		}
		if (fourthDotPosition == 2) { //325, 155
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX += 10;
			fourthDotY -= 5;

			if (fourthDotY == 100)
				fourthDotPosition = 3;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;

		}
		if (fourthDotPosition == 3) { //445, 105
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX += 10;
			fourthDotY += 5;

			if (fourthDotY == 160)
				fourthDotPosition = 4;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;

		}
		if (fourthDotPosition == 4) { //560, 170
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX += 5;
			fourthDotY += 10;

			if (fourthDotY == 290)
				fourthDotPosition = 5;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;

		}
		if (fourthDotPosition == 5) { //615, 300
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX -= 5;
			fourthDotY += 10;

			if (fourthDotY == 420)
				fourthDotPosition = 6;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;

		}
		if (fourthDotPosition == 6) { //545, 425
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX -= 10;
			fourthDotY += 5;

			if (fourthDotY == 480)
				fourthDotPosition = 7;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;

		}
		if (fourthDotPosition == 7) { //425, 475
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX -= 10;
			fourthDotY -= 5;

			if (fourthDotY == 420)
				fourthDotPosition = 8;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;
		}
		if (fourthDotPosition == 8) { //310, 410
			al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
			al_draw_filled_circle(fourthDotX, fourthDotY, 10, al_map_rgb(255, 255, 255));
			al_draw_line(440, 290, fourthDotX, fourthDotY, al_map_rgb(255, 255, 255), 2);

			fourthDotX -= 5;
			fourthDotY -= 10;

			if (fourthDotY == 290)
				fourthDotPosition = 1;

			fourthBall.xCoordinate = fourthDotX;
			fourthBall.yCoordinate = fourthDotY;
		}

		//START THE CIRCULAR MOTION FOR A THROWN BALL 
		for (int i = 0; i < ballthrowcounter - 1; i++) {
			if (ball[i].ballposition == 1) { //250, 290
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx += 5;
				ball[i].doty -= 10;


				if (ball[i].doty == 160)
					ball[i].ballposition = 2;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;

			}
			if (ball[i].ballposition == 2) { //325, 155
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx += 10;
				ball[i].doty -= 5;

				if (ball[i].doty == 100)
					ball[i].ballposition = 3;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;

			}
			if (ball[i].ballposition == 3) { //445, 105
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx += 10;
				ball[i].doty += 5;


				if (ball[i].doty == 160)
					ball[i].ballposition = 4;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;

			}
			if (ball[i].ballposition == 4) { //560, 170
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx += 5;
				ball[i].doty += 10;


				if (ball[i].doty == 290)
					ball[i].ballposition = 5;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;

			}
			if (ball[i].ballposition == 5) { //615, 300
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx -= 5;
				ball[i].doty += 10;


				if (ball[i].doty == 420)
					ball[i].ballposition = 6;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;

			}
			if (ball[i].ballposition == 6) { //545, 425
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx -= 10;
				ball[i].doty += 5;


				if (ball[i].doty == 480)
					ball[i].ballposition = 7;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;

			}
			if (ball[i].ballposition == 7) { //425, 475
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx -= 10;
				ball[i].doty -= 5;


				if (ball[i].doty == 420)
					ball[i].ballposition = 8;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;
			}
			if (ball[i].ballposition == 8) { //310, 410
				al_draw_filled_circle(440, 285, 50, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(ball[i].dotx, ball[i].doty, 10, al_map_rgb(255, 255, 255));
				al_draw_line(440, 290, ball[i].dotx, ball[i].doty, al_map_rgb(255, 255, 255), 2);

				ball[i].dotx -= 5;
				ball[i].doty -= 10;


				if (ball[i].doty == 290)
					ball[i].ballposition = 1;

				ball[i].xCoordinate = ball[i].dotx;
				ball[i].yCoordinate = ball[i].doty;
			}
		}

		//WE CHECK IF THE BALLS COLLIDE OR WHETHER THE GAME IS OVER
		if (finish == 1) {
			al_draw_filled_circle(425, 472, 10, al_map_rgb(255, 255, 255));
			break;
		}
		if (ballNumber > -2) {
			al_draw_filled_circle(440, 750, 10, al_map_rgb(255, 255, 255));
		}
		else {
			al_draw_filled_circle(440, 750, 10, al_map_rgb(0, 0, 0));
			win = 1;
			finish = 1;
		}

		//SENDING BOTTOM BALLS TO MAIN PART
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
			al_play_sample(soundeffect, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			ball[ballnumbercounter].dotx = 425;
			ball[ballnumbercounter].doty = 475;
			al_draw_filled_circle(ball[ballnumbercounter].xCoordinate, ball[ballnumbercounter].yCoordinate, 10, al_map_rgb(255, 255, 255));
			ballthrowcounter++;
			ballNumber--;

		}

		//WHEN WE SEND THE BOTTOM BALL TO MAIN PART, WE CHECK WHETHER THERE IS A MAIN BALL
		if (ballthrowcounter == 0) {
			if ((abs(firstBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(firstBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(secondBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(secondBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(thirdBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(thirdBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(fourthBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(fourthBall.yCoordinate - ball[ballnumbercounter].doty) <= 20)) {
				al_draw_filled_circle(440, 750, 10, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(432.5, 475, 10, al_map_rgb(255, 69, 0));
				finish = 1;
				lose = 1;
				al_play_sample(buzzSound, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			}
			else {
				ball[ballnumbercounter].ballposition = 7;
				ballnumbercounter = 1;
				ballthrowcounter = 1;
				finalBallNumber = 4;
			}
		}
		else if (ballthrowcounter == 4) {
			if ((abs(firstBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(firstBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(secondBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(secondBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(thirdBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(thirdBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(fourthBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(fourthBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[0].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[0].yCoordinate - ball[ballnumbercounter].doty) <= 20)) {
				al_draw_filled_circle(440, 750, 10, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(432.5, 475, 10, al_map_rgb(255, 69, 0));
				finish = 1;
				lose = 1;
				al_play_sample(buzzSound, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			}
			else {

				ball[ballnumbercounter].ballposition = 7;
				ballnumbercounter = 2;
				finalBallNumber = 3;
			}
		}
		else if (ballthrowcounter == 7) {
			if ((abs(firstBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(firstBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(secondBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(secondBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(thirdBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(thirdBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(fourthBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(fourthBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[0].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[0].yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[1].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[1].yCoordinate - ball[ballnumbercounter].doty) <= 20)) {
				al_draw_filled_circle(440, 750, 10, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(432.5, 475, 10, al_map_rgb(255, 69, 0));
				finish = 1;
				lose = 1;
				al_play_sample(buzzSound, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			}
			else {


				ball[ballnumbercounter].ballposition = 7;
				ballnumbercounter = 3;
				finalBallNumber = 2;

			}
		}
		else if (ballthrowcounter == 10) {
			if ((abs(firstBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(firstBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(secondBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(secondBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(thirdBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(thirdBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(fourthBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(fourthBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[0].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[0].yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[1].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[1].yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[2].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[2].yCoordinate - ball[ballnumbercounter].doty) <= 20)) {
				al_draw_filled_circle(440, 750, 10, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(432.5, 475, 10, al_map_rgb(255, 69, 0));
				finish = 1;
				lose = 1;
				al_play_sample(buzzSound, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			}
			else {


				ball[ballnumbercounter].ballposition = 7;
				ballnumbercounter = 4;
				finalBallNumber = 1;

			}
		}
		else if (ballthrowcounter == 13) {
			if ((abs(firstBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(firstBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(secondBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(secondBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(thirdBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(thirdBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(fourthBall.xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(fourthBall.yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[0].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[0].yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[1].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[1].yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[2].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[2].yCoordinate - ball[ballnumbercounter].doty) <= 20) ||
				(abs(ball[3].xCoordinate - ball[ballnumbercounter].dotx) <= 20 && abs(ball[3].yCoordinate - ball[ballnumbercounter].doty) <= 20)) {
				al_draw_filled_circle(440, 750, 10, al_map_rgb(255, 255, 255));
				al_draw_filled_circle(432.5, 475, 10, al_map_rgb(255, 69, 0));
				finish = 1;
				lose = 1;
				al_play_sample(buzzSound, 2.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			}
			else {
				ball[ballnumbercounter].ballposition = 7;
				ballnumbercounter = 5;
				finalBallNumber = 0;
			}
		}

		//WRITING THE GAME NAME AND SUM OF BALL WHICH WE HAVE
		al_draw_textf(font, al_map_rgb(0, 0, 0), 428, 270, 0, "aa");
		al_draw_filled_circle(472, 750, 12, al_map_rgb(0, 0, 0));
		al_draw_textf(font, al_map_rgb(255, 255, 255), 465, 735, 0, "%d", finalBallNumber);

		//DELETING INFORMATIONS
		if (finalBallNumber == 0) {
			al_draw_filled_circle(472, 750, 12, al_map_rgb(0, 0, 0));
		}

		//CHECKING WHETHER THE PLAYER LOSES OR WINS AND WRITING END MESSAGES  
		if (lose == 1) {
			al_draw_filled_circle(472, 750, 50, al_map_rgb(0, 0, 0));
			al_draw_textf(endFont, al_map_rgb(255, 255, 255), 210, 600, 0, "GAME OVER :(");
			al_play_sample(gameOver, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
		}
		if (win == 1) {
			al_draw_filled_circle(472, 750, 50, al_map_rgb(0, 0, 0));
			al_play_sample(winSound, 3.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			al_play_sample(clapSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
			al_draw_textf(endFont, al_map_rgb(255, 255, 255), 270, 600, 0, "YOU WIN!");
		}

		al_flip_display();
	}

	system("pause");
	return 0;
}