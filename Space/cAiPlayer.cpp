/*
=================
cAiPlayer.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cAiPlayer.h"

void cAiPlayer::render()
{


	glPushMatrix();

	glTranslatef(spritePos2D.x, spritePos2D.y, 0.0f);
	glRotatef(spriteRotation, 0.0f, 0.0f, 1.0f);
	glScalef(spriteScaling.x, spriteScaling.y, 1.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 

	glBegin(GL_QUADS);
	glColor3f(255.0f, 255.0f, 255.0f);
	glTexCoord2f(spriteTexCoordData[0].x, spriteTexCoordData[0].y);
	glVertex2f(-(textureWidth / 2), -(textureHeight / 2));
	glTexCoord2f(spriteTexCoordData[1].x, spriteTexCoordData[1].y);
	glVertex2f((textureWidth / 2), -(textureHeight / 2));
	glTexCoord2f(spriteTexCoordData[2].x, spriteTexCoordData[2].y);
	glVertex2f((textureWidth / 2), (textureHeight / 2));
	glTexCoord2f(spriteTexCoordData[3].x, spriteTexCoordData[3].y);
	glVertex2f(-(textureWidth / 2), (textureHeight / 2));

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cAiPlayer::update(float deltaTime)
{
	static bool goingRight= true;
	
	
	//changes direction when hit wall
	
	if (spritePos2D.x + (textureWidth / 2) == 1754){
		goingRight = false;
		//play the wall tap sound
		m_SoundMgr->getSnd("Tap")->playAudio(AL_TRUE);
	}
	
	else if (spritePos2D.x - (textureWidth / 2) == 0){
		goingRight = true;
	
		//play the wall tap sound
		m_SoundMgr->getSnd("Tap")->playAudio(AL_TRUE);
	} 
	//set speed
	if (goingRight){
		spritePos2D.x += 1.0f;
	}
	else if (!goingRight){
		spritePos2D.x -= 1.0f;
	}
	

	setBoundingRect(&boundingRect);

}
/*
=================================================================
  Sets the velocity for the Asteroid
=================================================================
*/
void cAiPlayer::setAsteroidVelocity(glm::vec2 AsteroidVel)
{
	asteroidVelocity = AsteroidVel;
}
/*
=================================================================
  Gets the Asteroid velocity
=================================================================
*/
glm::vec2 cAiPlayer::getAsteroidVelocity()
{
	return asteroidVelocity;
}
/*
==========================================================================
Use this method to show the collision box.
==========================================================================
*/
void cAiPlayer::renderCollisionBox()
{
	glPushMatrix();

	glTranslatef(boundingRect.left, boundingRect.top, 0.0f);
	//glRotatef(spriteRotation, 0.0f, 0.0f, 1.0f);
	//glScalef(spriteScaling.x, spriteScaling.y, 1.0f);

	glColor3f(255.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	//glVertex2f(-(textureWidth / 2), -(textureHeight / 2));
	//glVertex2f((textureWidth / 2), -(textureHeight / 2));
	//glVertex2f((textureWidth / 2), (textureHeight / 2));
	//glVertex2f(-(textureWidth / 2), (textureHeight / 2));

	glVertex2f(-((boundingRect.right - boundingRect.left) / 2), -((boundingRect.bottom - boundingRect.top)/2));
	glVertex2f(((boundingRect.right - boundingRect.left) / 2), -((boundingRect.bottom - boundingRect.top) / 2));
	glVertex2f(((boundingRect.right - boundingRect.left) / 2), ((boundingRect.bottom - boundingRect.top) / 2));
	glVertex2f(-((boundingRect.right - boundingRect.left) / 2), ((boundingRect.bottom - boundingRect.top) / 2));
	glEnd();

	glPopMatrix();
}