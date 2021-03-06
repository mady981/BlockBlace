/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    fel( gfx ),
    player_pos( { 100,100 } )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if ( wnd.kbd.KeyIsPressed( VK_UP ) )
    {
        --player_pos.y;
    }
    else if ( wnd.kbd.KeyIsPressed( VK_DOWN ) )
    {
        ++player_pos.y;
    }
    else if ( wnd.kbd.KeyIsPressed( VK_LEFT ) )
    {
        --player_pos.x;
    }
    else if ( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
    {
        ++player_pos.x;
    }
    if ( wnd.mouse.LeftIsPressed() )
    {
        VectorI mouse_pos = { wnd.mouse.GetPosX(),wnd.mouse.GetPosY() };
        if ( fel.getFieldHB().isOverlappingWith( mouse_pos ) )
        {
            fel.PlaceBlock( mouse_pos,player_pos );
        }
        fel.getBlock( mouse_pos );
    }
}

void Game::ComposeFrame()
{
    fel.Border();
    fel.DrawBlockBar();
    fel.DrawSeenField( player_pos );
}
