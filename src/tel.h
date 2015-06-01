/*
   Phobia Motor Controller for RC and robotics.
   Copyright (C) 2015 Roman Belov <romblv@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _H_TEL_
#define _H_TEL_

#define	TELSZ			40000

typedef struct {

	int			enabled;

	short int		p_list[8];
	int			p_size;

	int			s_average[8];
	int			s_clock, s_clock_scale;

	short int		pD[TELSZ];
	short int		*pZ;
}
tel_t;

extern tel_t			tel;

void tel_capture();
void tel_flush();

#endif /* _H_TEL_ */
