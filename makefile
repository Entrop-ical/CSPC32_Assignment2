all: social astroworld

social: main.c platform.c post.c comment.c reply.c
	gcc main.c platform.c post.c comment.c reply.c -o social

astroworld: astroworld.c
	gcc astroworld.c -o astroworld

clean:
	rm -f social astroworld
