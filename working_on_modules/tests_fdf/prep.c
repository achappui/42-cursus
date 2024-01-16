void oct_8(t_screen_point *p1, t_screen_point *p2, t_util *u)
{
    unsigned int	pixel_nb;
	int				err;
	int				dx;
	int				dy;
	char			*dst;

    dx = p2->x - p1->x ;
    dy = p2->y - p1->y ;
    err = -dx >> 1 ;
    pixel_nb = p2->x - p1->x + 1;
	p2->a = (p2->a - p1->a) / pixel_nb;
	p2->r = (p2->r - p1->r) / pixel_nb;
	p2->g = (p2->g - p1->g) / pixel_nb;
	p2->b = (p2->b - p1->b) / pixel_nb;
	while (pixel_nb-- > 0)
	{
        dst = data->addr + (p1->y * data->line_length + p1->x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = ((p1->a >> 24) << 24) + ((p1->r >> 24) << 16) + ((p1->g >> 24) << 8) + (p1->b >> 24);
        err += dy;
        if(err > 0)
        {
            err -= dx;
            p1->y++;
        }
        p1->x++;
		p1->a += p2->a;
		p1->r += p2->r;
		p1->g += p2->g;
		p1->b += p2->b;
	}
}

void oct_1(t_screen_point *p1, t_screen_point *p2, t_util *u)
{
    unsigned int	pixel_nb;
	int				err;
	int				dx;
	int				dy;
	char			*dst;

    dx = p2->x - p1->x ;
    dy = p2->y - p1->y ;
    err = dx >> 1 ;
    pixel_nb = p2->x - p1->x + 1;
	p2->a = (p2->a - p1->a) / pixel_nb;
	p2->r = (p2->r - p1->r) / pixel_nb;
	p2->g = (p2->g - p1->g) / pixel_nb;
	p2->b = (p2->b - p1->b) / pixel_nb;
	while (pixel_nb-- > 0)
	{
        dst = data->addr + (p1->y * data->line_length + p1->x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = ((p1->a >> 24) << 24) + ((p1->r >> 24) << 16) + ((p1->g >> 24) << 8) + (p1->b >> 24);
        err += dy;
        if(err < 0)
        {
            err += dx;
            p1->y--;
        }
        p1->x++;
		p1->a += p2->a;
		p1->r += p2->r;
		p1->g += p2->g;
		p1->b += p2->b;
	}
}

void oct_2(t_screen_point *p1, t_screen_point *p2, t_util *u)
{
    unsigned int	pixel_nb;
	int				err;
	int				dx;
	int				dy;
	char			*dst;

    dx = p2->x - p1->x ;
    dy = p2->y - p1->y ;
    err = dy >> 1 ;
    pixel_nb = p1->y - p2->y + 1;
	p2->a = (p2->a - p1->a) / pixel_nb;
	p2->r = (p2->r - p1->r) / pixel_nb;
	p2->g = (p2->g - p1->g) / pixel_nb;
	p2->b = (p2->b - p1->b) / pixel_nb;
	while (pixel_nb-- > 0)
	{
        dst = data->addr + (p1->y * data->line_length + p1->x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = ((p1->a >> 24) << 24) + ((p1->r >> 24) << 16) + ((p1->g >> 24) << 8) + (p1->b >> 24);
        err += dx;
        if(err > 0)
        {
            err += dy;
            p1->x++;
        }
        p1->y--;
		p1->a += p2->a;
		p1->r += p2->r;
		p1->g += p2->g;
		p1->b += p2->b;
	}
}

void oct_7(t_screen_point *p1, t_screen_point *p2, t_util *u)
{
    unsigned int	pixel_nb;
	int				err;
	int				dx;
	int				dy;
	char			*dst;

    dx = p2->x - p1->x ;
    dy = p2->y - p1->y ;
    err = -dy >> 1 ;
    pixel_nb = p2->y - p1->y + 1;
	p2->a = (p2->a - p1->a) / pixel_nb;
	p2->r = (p2->r - p1->r) / pixel_nb;
	p2->g = (p2->g - p1->g) / pixel_nb;
	p2->b = (p2->b - p1->b) / pixel_nb;
	while (pixel_nb-- > 0)
	{
        dst = data->addr + (p1->y * data->line_length + p1->x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = ((p1->a >> 24) << 24) + ((p1->r >> 24) << 16) + ((p1->g >> 24) << 8) + (p1->b >> 24);
        err += dx;
        if(err > 0)
        {
            err -= dy;
            p1->x++;
        }
        p1->y++;
		p1->a += p2->a;
		p1->r += p2->r;
		p1->g += p2->g;
		p1->b += p2->b;
	}
}