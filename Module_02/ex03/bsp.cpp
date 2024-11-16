/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:28:02 by schamizo          #+#    #+#             */
/*   Updated: 2024/11/16 16:33:01 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	two_point_distance(const Point &a, const Point &b)
{
	float	distance = 0.0f;
	float	x1 = a.getX().toFloat();
	float	y1 = a.getY().toFloat();
	float	x2 = b.getX().toFloat();
	float	y2 = b.getY().toFloat();

	distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (distance);
}

float	calculate_area(float distance_a, float distance_b, float distance_c)
{
	float	semi_perimeter = 0.0f;
	float	area = 0.0f;

	//sp = (a + b + c) / 2.0
	semi_perimeter = (distance_a + distance_b + distance_c) / 2.0;

	//area = sqrt(sp * (sp - a) * (sp - b) * (sp - c))
	area = sqrt(semi_perimeter * (semi_perimeter - distance_a) \
		* (semi_perimeter - distance_b) * (semi_perimeter - distance_c));
	return (area);
}

int		position(float area, float area_A, float area_B, float area_C)
{
	float res = area - (area_A + area_B + area_C);

	if (!area_A || !area_B || !area_C)
		return (0);
	if (res < 0)
	{
		res = -res;
	}
	if (res == 0 || res < 0.001)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool	bsp(const Point &a, const Point &b, const Point &c,const Point &point)
{
    float	distance_a = 0.0f;
	float	distance_b = 0.0f;
	float	distance_c = 0.0f;
	float	distance_d = 0.0f;
	float	distance_e = 0.0f;
	float	distance_f = 0.0f;
	float	area = 0.0f;
	float	area_A = 0.0f;
	float	area_B = 0.0f;
	float	area_C = 0.0f;

	distance_a = two_point_distance(a, b);
	distance_b = two_point_distance(b, c);
	distance_c = two_point_distance(c, a);

	distance_d = two_point_distance(a, point);
	distance_e = two_point_distance(b, point);
	distance_f = two_point_distance(c, point);

	area = calculate_area(distance_a, distance_b, distance_c);
	area_A = calculate_area(distance_a, distance_d, distance_e);
	area_B = calculate_area(distance_b, distance_f, distance_e);
	area_C = calculate_area(distance_c, distance_d, distance_f);

	if (position(area, area_A, area_B, area_C))
	{
		std::cout << "The point is inside the triangle\n";
		return (true);
	}
	else
	{
		std::cout << "The point is outside the triangle\n";
		return (false);
	}
}

/*                                a                                                                    
                                    --=                                                             
                                   = :  .-                                                          
                                  .        =                                                        
                                :     *       *                                                     
                               -      +          +                                                  
                              =        :           :.                                               
                             =         -              *                                      
                            :           +               *                                          
                          +             *                   =                                       
                         =              :                     =:    distance_c                                
       distance_a      +     area_A     =      Area_C            *                                  
                      :                  *                          +                               
                     =                  +  .+-                        :=                            
                    =               :=  point     +-                     *                          
                   =             +                     .+                   *                       
                  .          :=                              -+                *                    
                :         +                                       ==            ::                 
               =       *                area_B                           +-         +               
              =    +:                                                          +=      +            
             .  *                                                                   .+-  .-         
            == +: * = + - : = + * - *: +* = := +* ., = +: * = : +:= * .: +* = +*: += == : :-+       
          b                                distance_b                                         c      
                                                                                               */ 