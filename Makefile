CFLAGS = -Wall
OBJDIR = obj
SRCDIR = src
HDIR = h

.PRECIOUS: $(OBJDIR)/%.o

clean:
	rm -rf $(OBJDIR)/*.o *.x

all: client.x

%.x: $(OBJDIR)/%.o
	gcc $(CFLAGS) -o $@ $< 
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDIR)/%.h
	gcc $(CFLAGS) -c $< -o $@


