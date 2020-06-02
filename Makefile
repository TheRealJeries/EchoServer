CFLAGS = -Wall
OBJDIR = obj
SRCDIR = src
HDIR = h

.PRECIOUS: $(OBJDIR)/%.o

clean:
	rm -rf $(OBJDIR)/*.o *.x

all: client.x server.x



%.x: $(OBJDIR)/%.o $(OBJDIR)/common.o
	gcc $(CFLAGS) -o $@ $^ 


$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDIR)/common.h
	gcc $(CFLAGS) -c $< -o $@

