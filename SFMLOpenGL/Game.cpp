#include <Game.h>
//@Author Sean Nash De Andrade
//@Login C00217019
//Cube Buffer Assignment
//Known Issues: Translation breaks apart the cube. Unsure as to the cause.
static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO - Seans Nash")
{
	initialize();
}

Game::~Game() {}

void Game::run()
{

	

	Event event;

	while (isRunning) {

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}
	
}

typedef struct
{
	float coordinate[3];
	float color[3];
} VertexStruct;

VertexStruct m_vertex[36]; //Struct Declaration
GLubyte m_triangle[36]; 

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */
	arraySetup();//Sets up the transformable Vertexs
	updateVertices();//Sets up the Vertex Locations
	setUpColour();//Sets up the Vertex colours

	for (int index = 0; index < 36; index++)
	{
		m_triangle[index] = index;
	}

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexStruct) * 36, m_vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, m_triangle, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Rotates Up around X axis
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationX(.01);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Rotates Down around X axis
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationX(-.01);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//Rotates Right around Y Axis
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationY(.01);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//Rotates Left around Y Axis
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationY(-.01);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))//Rotates Right around the Z Axis
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationZ(.01);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))//Rotates Left around the Z Axis
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationZ(-.01);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Moves Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.Translate(0.001, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Moves Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.Translate(-0.001, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))//Scales Down
	{
		m_changed = true;
		m_Matrix = m_Matrix.Scale3D(99.95);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Scales Up
	{
		m_changed = true;
		m_Matrix = m_Matrix.Scale3D(100.05);
	}

	if (m_changed == true)//If something has needs to be changed the bool is reset and the vertices are transformed by the matrix
	{
		m_changed = false;
		transformVertices();
	}
	updateVertices();//Updates all the Vertices


}

void Game::render()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexStruct) * 36, m_vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(VertexStruct), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(VertexStruct), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

void Game::setUpColour()
{
	int triangleTracker = 0;
	for (int i = 0; i < 36; i++)//For all the vertexes
	{
		if (i != 0 && i % 6 == 0)//Increase the colour count once the current side is finished
		{
			index += 1;
		}
		m_vertex[i].color[0] = m_colourArray[index].x;
		m_vertex[i].color[1] = m_colourArray[index].y;
		m_vertex[i].color[2] = m_colourArray[index].z;
	}
}

void Game::arraySetup()
{
	m_transformableVertex[0] = MyVector3(0.25, 0.25, -0.1);//Front Side Top Right Corner
	m_transformableVertex[1] = MyVector3(-0.25, 0.25, -0.1);//Front Side Bottom Right Corner
	m_transformableVertex[2] = MyVector3(-0.25, -0.25, -0.1);//Front Side Bottom Left Corner
	m_transformableVertex[3] = MyVector3(0.25, -0.25, -0.1); //Front Side Top Left Corner

	m_transformableVertex[4] = MyVector3(0.25, 0.25, -0.5);//Back Side Top Right Corner
	m_transformableVertex[5] = MyVector3(-0.25, 0.25, -0.5);//Back Side Bottom Right Corner
	m_transformableVertex[6] = MyVector3(-0.25, -0.25, -0.5);//Back Side Top Left Corner
	m_transformableVertex[7] = MyVector3(0.25, -0.25, -0.5);//Back Side Bottom Left Corner
}

void Game::updateVertices()
{
	int temptIndex = 0;
	for (int i = 0; i < 8; i++)//Sets the current Corner Vectors into an array of doubles.
	{
		temptIndex = i * 3;
		m_vertexArray[temptIndex] = m_transformableVertex[i].getX();//Takes the transformable Vectors and turns them into 3 double values
		m_vertexArray[temptIndex + 1] = m_transformableVertex[i].getY();
		m_vertexArray[temptIndex + 2] = m_transformableVertex[i].getZ();
	}
	temptIndex = 0;
	for (int i = 0; i < 36; i++)//Sets the doubles values to the correct vertex.
	{
		m_vertex[i].coordinate[0] = m_vertexArray[vertex_index[i]*3];//The Correct values are given to the correct vertex using the Vertex_index
		m_vertex[i].coordinate[1] = m_vertexArray[vertex_index[i]*3+1];
		m_vertex[i].coordinate[2] = m_vertexArray[vertex_index[i]*3+2];
	}

}

void Game::transformVertices()
{
	for (int i = 0; i < 8; i++)
	{
		m_transformableVertex[i] = m_transformableVertex[i] * m_Matrix;//Applies the transformation matrix to all transformable Vertices
	}
}

