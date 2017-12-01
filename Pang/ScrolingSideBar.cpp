#include "ScrolingSideBar.h"

// -----------------------------  Constructor for SideScrollBar -------------------------------------------------------
SideScrollBar::SideScrollBar(float* startingValue, const float maxValue, const std::string name)
{
	font.loadFromFile("arial.ttf");
	currentValue = startingValue;
	this->maxValue = maxValue;
	this->name = name;
	value = std::to_string(int(*currentValue));
	currentPosition = (100.0f / maxValue * *currentValue) + 10.0f;
	//position is a sf::Vector witch contains the position 
	position.x = 60.0f;
	position.y = 20.0f + 40.0f * SideScrollBar::counter;
	counter++;
}
//---------------------------------------------------------------------------------------------------------------------
//------------------- Initialise is a method that sets all the paramiters for visual objects --------------------------
void SideScrollBar::initialise(sf::RenderWindow &window)
{
	//		the container is the rect that contains all olther objects 
	container.setSize(sf::Vector2f(containerWidth, containerHeight));
	container.setOrigin(containerWidth / 2, containerHeight / 2);
	container.setPosition(position.x, position.y);

	
	container.setOutlineThickness(2);
	container.setOutlineColor(sf::Color::Blue);

	//		the line is 100 pixel long which represents the percentage
	line.setSize(sf::Vector2f(100, 3));
	line.setOrigin(50, 2);
	line.setFillColor(sf::Color::Black);
	line.setPosition(container.getPosition().x, container.getPosition().y + 8);	//this bounds the origin of our line
																				//to the coitainers origin 

	/*		The pivot is the most important element of this class it is the
			element which we move in order to change the value that we want
			to control with our side bar.										*/
	pivot.setSize(sf::Vector2f(7, 16));
	pivot.setOrigin(3, 8);
	pivot.setFillColor(sf::Color::Green);
	pivot.setPosition(currentPosition, container.getPosition().y + 8);

	//		The hide box is a rect that is constantly shown on the screen
	//		when we click on it the side bar is shown or hidden
	hideBox.setSize(sf::Vector2f(6, containerHeight));
	hideBox.setOrigin(3, containerHeight / 2);
	hideBox.setPosition(3, container.getPosition().y);
	hideBox.setFillColor(sf::Color::Blue);

	//		the label is the name that we give to our side bar
	label.setFont(font);
	label.setString(name);
	label.setCharacterSize(12);
	label.setPosition(sf::Vector2f(container.getPosition().x - label.getLocalBounds().width / 2, container.getPosition().y - 20.0f));
	label.setColor(sf::Color::Black);

	//		the valueLabel represents the current value of the variable 
	valueLabel.setFont(font);
	valueLabel.setString(value);
	valueLabel.setCharacterSize(10);
	valueLabel.setPosition(sf::Vector2f(container.getLocalBounds().width - 25, container.getPosition().y - 20.0f));
	valueLabel.setColor(sf::Color::Black);

	//		this make sure that if we have more than 1 side bar the outline borders do not overlap
	position.y = position.y + (SideScrollBar::counter == 1 ? 2 : 0);

	//		in the end we draw only the hideBox so the user can decide to show the side bar when needed
	if (hide)
		window.draw(hideBox);
	else
		draw(window);
}
//----------------------------------------------------------------------------------------------------------------------
//------------ The update method checks if the side bar is hidden or not and depending on the result -------------------
//------------ it calls the apropriate methods -------------------------------------------------------------------------
void SideScrollBar::update(sf::RenderWindow &window)
{
	if (hide)
	{
		//		In case side bar is hidden it just draws the hideBox
		window.draw(hideBox);
	}
	else
	{
		//		In case the side bar is shown it fistly calls the move method 
		//		then it calls the draw method
		move(window);
		draw(window);
	}

}
//----------------------------------------------------------------------------------------------------------------------
//------ The draw method is responsable for drawing all parts of our side bar to the screen in a corrct order ----------
void SideScrollBar::draw(sf::RenderWindow& window)
{
	window.draw(container);
	window.draw(hideBox);
	window.draw(line);
	window.draw(pivot);
	window.draw(label);
	window.draw(valueLabel);

}
//----------------------------------------------------------------------------------------------------------------------
//----- There are two methods setPosition which do exactly the same thisng but accept slightly different parameters ----
//----- the first one accept a mathematicat vector ---------------------------------------------------------------------
void SideScrollBar::setPosition(sf::Vector2f position)
{
	this->position = position;
}

//----- the second one accept two float --------------------------------------------------------------------------------
void SideScrollBar::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}
//----------------------------------------------------------------------------------------------------------------------
//--------------- The reduce method is responsable for changing the hide flag when the hitBox was clicked --------------
void SideScrollBar::reduce(sf::RenderWindow& window)
{
	localPosition = sf::Mouse::getPosition(window);

	if (hit(localPosition, hideBox))
	{
		hide = !hide;
	}
}
//----------------------------------------------------------------------------------------------------------------------
//-------- The hit method is the method which checks for collission between the mouse and every olther rectangle -------
//-------- that we pass at its inside ----------------------------------------------------------------------------------
bool SideScrollBar::hit(sf::Vector2i mousePosition, sf::RectangleShape rectangle)
{

	if (mousePosition.x > rectangle.getGlobalBounds().left
		&& mousePosition.x < rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width
		&& mousePosition.y > rectangle.getGlobalBounds().top
		&& mousePosition.y < rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height)
	{
		//		if the mouse position is inside the rectangle 	
		return true;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------------------------------------------------------
//----------------------- The move method is the one that actually does something with the pivot -----------------------
void SideScrollBar::move(sf::RenderWindow& window)
{
	localPosition = sf::Mouse::getPosition(window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// if the mouse button is presed and it hits the pivot, hitPivot will be true as long as 
		// the button is pressed so we dont have to keep the mouse cursor egsactly on the pivot 
		// it is necessary that we hit the pivot only one time to set it to be true untill we release the button
		if (hit(localPosition, pivot))
			hitPivot = true;
	}
	else
	{
		//in case the mouse button is not pressed hitPivot is alweys set to be false 
		hitPivot = false;
	}

	//The pivot logic is run only when hit pivot is ture
	if (hitPivot)
	{
		//positio of the pivot is set = to the x of the mouse 
		currentPosition = localPosition.x;

		//then we checks if the currentPositin isn't bigger than the line right side 
		// if it is we set it to be equal to that value 
		if (currentPosition > line.getPosition().x + line.getGlobalBounds().width / 2)
			currentPosition = line.getPosition().x + line.getGlobalBounds().width / 2;

		// we check the same thing for the left side of the line 
		if (currentPosition < line.getPosition().x - line.getGlobalBounds().width / 2)
			currentPosition = line.getPosition().x - line.getGlobalBounds().width / 2;

		//after those checks we change the pivot x position to the value stored in curentPosition
		pivot.setPosition(currentPosition, pivot.getPosition().y);

		//this lane of code changes the actual value of the variable that the user want to change at run time
		// we subtract 10 form the position becouse we set the origin of the container equal to 60
		// and that of the line to 50 it is the difference between the two values 
		// this difference is  simply for cosmetic reasons 
		*currentValue = maxValue / 100 * (currentPosition - 10);

		//On the following lines we use to_sting function to convert form float to stirng
		// we also cast the float value to int to get ride of all extra zeros on the screen 
		value = std::to_string(int(*currentValue));
		valueLabel.setString(value);
	}

}

//static 
int SideScrollBar::counter = 0;
