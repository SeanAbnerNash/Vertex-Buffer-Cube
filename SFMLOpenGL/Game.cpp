#include <Game.h>
//@Author Sean Nash De Andrade
//@Login C00217019
//Cube Buffer Assignment
static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO - Seans Nash")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

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

VertexStruct vertex[36]; //Struct Declaration
GLubyte triangles[36]; 

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */
	arraySetup();
	updateVertices();
	vertex[0].color[0] = 0.1f;//Colour Declaration
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 4.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;


	vertex[6].color[0] = 0.1f;
	vertex[6].color[1] = 1.0f;
	vertex[6].color[2] = 4.0f;

	vertex[7].color[0] = 0.2f;
	vertex[7].color[1] = 4.0f;
	vertex[7].color[2] = 0.0f;

	vertex[8].color[0] = 0.3f;
	vertex[8].color[1] = 4.0f;
	vertex[8].color[2] = 0.0f;

	vertex[9].color[0] = 0.4f;
	vertex[9].color[1] = 1.0f;
	vertex[9].color[2] = 4.0f;

	vertex[10].color[0] = 4.5f;
	vertex[10].color[1] = 1.0f;
	vertex[10].color[2] = 0.0f;

	vertex[11].color[0] = 1.6f;
	vertex[11].color[1] = 13.0f;
	vertex[11].color[2] = 0.0f;

	vertex[12].color[0] = 14.6f;
	vertex[12].color[1] = 10.0f;
	vertex[12].color[2] = 0.0f;

	vertex[13].color[0] = 21.6f;
	vertex[13].color[1] = 1.0f;
	vertex[13].color[2] = 0.0f;

	vertex[14].color[0] = 0.6f;
	vertex[14].color[1] = 1.0f;
	vertex[14].color[2] = 0.0f;

	vertex[15].color[0] = 8.6f;
	vertex[15].color[1] = 8.0f;
	vertex[15].color[2] = 8.0f;

	vertex[16].color[0] = 7.6f;
	vertex[16].color[1] = 7.0f;
	vertex[16].color[2] = 0.0f;

	vertex[17].color[0] = 7.6f;
	vertex[17].color[1] = 1.0f;
	vertex[17].color[2] = 0.0f;

	vertex[18].color[0] = 7.6f;
	vertex[18].color[1] = 1.0f;
	vertex[18].color[2] = 0.0f;

	vertex[19].color[0] = 5.6f;
	vertex[19].color[1] = 1.0f;
	vertex[19].color[2] = 0.0f;

	vertex[20].color[0] = 0.6f;
	vertex[20].color[1] = 1.0f;
	vertex[20].color[2] = 0.0f;

	vertex[21].color[0] = 7.6f;
	vertex[21].color[1] = 1.0f;
	vertex[21].color[2] = 0.0f;

	vertex[22].color[0] = 0.6f;
	vertex[22].color[1] = 1.0f;
	vertex[22].color[2] = 7.0f;

	vertex[23].color[0] = 0.6f;
	vertex[23].color[1] = 1.0f;
	vertex[23].color[2] = 0.0f;

	vertex[24].color[0] = 0.6f;
	vertex[24].color[1] = 6.0f;
	vertex[24].color[2] = 0.0f;

	vertex[24].color[0] = 0.6f;
	vertex[24].color[1] = 1.0f;
	vertex[24].color[2] = 6.0f;

	vertex[24].color[0] = 0.6f;
	vertex[24].color[1] = 1.0f;
	vertex[24].color[2] = 0.0f;

	vertex[25].color[0] = 05.6f;
	vertex[25].color[1] = 1.0f;
	vertex[25].color[2] = 0.0f;

	vertex[26].color[0] = 0.6f;
	vertex[26].color[1] = 1.0f;
	vertex[26].color[2] = 20.0f;

	vertex[27].color[0] = 0.6f;
	vertex[27].color[1] = 1.0f;
	vertex[27].color[2] = 22.0f;

	vertex[28].color[0] = 22.6f;
	vertex[28].color[1] = 1.0f;
	vertex[28].color[2] = 0.0f;

	vertex[29].color[0] = 1.6f;
	vertex[29].color[1] = 1.0f;
	vertex[29].color[2] = 1.0f;

	vertex[30].color[0] = 7.6f;
	vertex[30].color[1] = 4.0f;
	vertex[30].color[2] = 0.0f;

	vertex[31].color[0] = 5.6f;
	vertex[31].color[1] = 1.0f;
	vertex[31].color[2] = 0.0f;

	vertex[32].color[0] = 0.6f;
	vertex[32].color[1] = 1.0f;
	vertex[32].color[2] = 2.0f;



	for (int index = 0; index < 36; index++)
	{
		triangles[index] = index;
	}

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexStruct) * 6, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 6, triangles, GL_STATIC_DRAW);
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




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//Rotates Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationX(1);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Rotates Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationX(-1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))//Rotates Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationY(1);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))//Rotates Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationY(-1);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))//Rotates Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationY(1);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))//Rotates Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.RotationZ(-1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Moves Right
	{
		m_changed = true;
		m_Matrix = m_Matrix.Translate(0.001, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Moves Left
	{
		m_changed = true;
		m_Matrix = m_Matrix.Translate(-0.001, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))//Scales Down
	{
		m_changed = true;
		m_Matrix = m_Matrix.Scale(99.5, 99.5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))//Scales Up
	{
		m_changed = true;
		m_Matrix = m_Matrix.Scale(100.5, 100.5);
	}

	if (m_changed == true)
	{
		m_changed = false;
		transformVertices();
	}
	updateVertices();


}

void Game::render()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexStruct) * 36, vertex, GL_STATIC_DRAW);

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

void Game::arraySetup()
{
	m_transformableVertex[0] = MyVector3(0.25, 0.25, 0.1);//Front Side Top Right Corner
	m_transformableVertex[1] = MyVector3(-0.25, 0.25, 0.1);//Front Side Bottom Right Corner
	m_transformableVertex[2] = MyVector3(-0.25, -0.25, 0.1);//Front Side Bottom Left Corner
	m_transformableVertex[3] = MyVector3(0.25, -0.25, 0.1); //Front Side Top Left Corner

	m_transformableVertex[4] = MyVector3(0.25, 0.25, 0.5);//Back Side Top Right Corner
	m_transformableVertex[5] = MyVector3(-0.25, 0.25, 0.5);//Back Side Bottom Right Corner
	m_transformableVertex[6] = MyVector3(-0.25, -0.25, 0.5);//Back Side Top Left Corner
	m_transformableVertex[7] = MyVector3(0.25, -0.25, 0.5);//Back Side Bottom Left Corner
}

void Game::updateVertices()
{
	/*vertex[0].coordinate[0] = m_transformableVertex[0].getX();//Old Hardcoded Values
	vertex[0].coordinate[1] = m_transformableVertex[0].getY();
	vertex[0].coordinate[2] = m_transformableVertex[0].getZ();

	vertex[1].coordinate[0] = m_transformableVertex[1].getX();
	vertex[1].coordinate[1] = m_transformableVertex[1].getY();
	vertex[1].coordinate[2] = m_transformableVertex[1].getZ();

	vertex[2].coordinate[0] = m_transformableVertex[2].getX();
	vertex[2].coordinate[1] = m_transformableVertex[2].getY();
	vertex[2].coordinate[2] = m_transformableVertex[2].getZ();

	vertex[3].coordinate[0] = m_transformableVertex[0].getX();
	vertex[3].coordinate[1] = m_transformableVertex[0].getY();
	vertex[3].coordinate[2] = m_transformableVertex[0].getZ();

	vertex[4].coordinate[0] = m_transformableVertex[2].getX();
	vertex[4].coordinate[1] = m_transformableVertex[2].getY();
	vertex[4].coordinate[2] = m_transformableVertex[2].getZ();

	vertex[5].coordinate[0] = m_transformableVertex[3].getX();
	vertex[5].coordinate[1] = m_transformableVertex[3].getY();
	vertex[5].coordinate[2] = m_transformableVertex[3].getZ();

	vertex[6].coordinate[0] = m_transformableVertex[4].getX();
	vertex[6].coordinate[1] = m_transformableVertex[4].getY();
	vertex[6].coordinate[2] = m_transformableVertex[4].getZ();

	vertex[7].coordinate[0] = m_transformableVertex[5].getX();
	vertex[7].coordinate[1] = m_transformableVertex[5].getY();
	vertex[7].coordinate[2] = m_transformableVertex[5].getZ();

	vertex[8].coordinate[0] = m_transformableVertex[6].getX();
	vertex[8].coordinate[1] = m_transformableVertex[6].getY();
	vertex[8].coordinate[2] = m_transformableVertex[6].getZ();

	vertex[9].coordinate[0] = m_transformableVertex[4].getX();
	vertex[9].coordinate[1] = m_transformableVertex[4].getY();
	vertex[9].coordinate[2] = m_transformableVertex[4].getZ();

	vertex[10].coordinate[0] = m_transformableVertex[6].getX();
	vertex[10].coordinate[1] = m_transformableVertex[6].getY();
	vertex[10].coordinate[2] = m_transformableVertex[6].getZ();

	vertex[11].coordinate[0] = m_transformableVertex[7].getX();
	vertex[11].coordinate[1] = m_transformableVertex[7].getY();
	vertex[11].coordinate[2] = m_transformableVertex[7].getZ();

	vertex[12].coordinate[0] = m_transformableVertex[1].getX();
	vertex[12].coordinate[1] = m_transformableVertex[1].getY();
	vertex[12].coordinate[2] = m_transformableVertex[1].getZ();

	vertex[13].coordinate[0] = m_transformableVertex[2].getX();
	vertex[13].coordinate[1] = m_transformableVertex[2].getY();
	vertex[13].coordinate[2] = m_transformableVertex[2].getZ();

	vertex[14].coordinate[0] = m_transformableVertex[5].getX();
	vertex[14].coordinate[1] = m_transformableVertex[5].getY();
	vertex[14].coordinate[2] = m_transformableVertex[5].getZ();

	vertex[15].coordinate[0] = m_transformableVertex[2].getX();
	vertex[15].coordinate[1] = m_transformableVertex[2].getY();
	vertex[15].coordinate[2] = m_transformableVertex[2].getZ();

	vertex[16].coordinate[0] = m_transformableVertex[5].getX();
	vertex[16].coordinate[1] = m_transformableVertex[5].getY();
	vertex[16].coordinate[2] = m_transformableVertex[5].getZ();

	vertex[17].coordinate[0] = m_transformableVertex[6].getX();
	vertex[17].coordinate[1] = m_transformableVertex[6].getY();
	vertex[17].coordinate[2] = m_transformableVertex[6].getZ();

	vertex[18].coordinate[0] = m_transformableVertex[0].getX();
	vertex[18].coordinate[1] = m_transformableVertex[0].getY();
	vertex[18].coordinate[2] = m_transformableVertex[0].getZ();

	vertex[19].coordinate[0] = m_transformableVertex[3].getX();
	vertex[19].coordinate[1] = m_transformableVertex[3].getY();
	vertex[19].coordinate[2] = m_transformableVertex[3].getZ();

	vertex[20].coordinate[0] = m_transformableVertex[4].getX();
	vertex[20].coordinate[1] = m_transformableVertex[4].getY();
	vertex[20].coordinate[2] = m_transformableVertex[4].getZ();

	vertex[21].coordinate[0] = m_transformableVertex[3].getX();
	vertex[21].coordinate[1] = m_transformableVertex[3].getY();
	vertex[21].coordinate[2] = m_transformableVertex[3].getZ();

	vertex[22].coordinate[0] = m_transformableVertex[4].getX();
	vertex[22].coordinate[1] = m_transformableVertex[4].getY();
	vertex[22].coordinate[2] = m_transformableVertex[4].getZ();

	vertex[23].coordinate[0] = m_transformableVertex[7].getX();
	vertex[23].coordinate[1] = m_transformableVertex[7].getY();
	vertex[23].coordinate[2] = m_transformableVertex[7].getZ();

	vertex[24].coordinate[0] = m_transformableVertex[0].getX();
	vertex[24].coordinate[1] = m_transformableVertex[0].getY();
	vertex[24].coordinate[2] = m_transformableVertex[0].getZ();

	vertex[25].coordinate[0] = m_transformableVertex[1].getX();
	vertex[25].coordinate[1] = m_transformableVertex[1].getY();
	vertex[25].coordinate[2] = m_transformableVertex[1].getZ();

	vertex[26].coordinate[0] = m_transformableVertex[4].getX();
	vertex[26].coordinate[1] = m_transformableVertex[4].getY();
	vertex[26].coordinate[2] = m_transformableVertex[4].getZ();

	vertex[27].coordinate[0] = m_transformableVertex[1].getX();
	vertex[27].coordinate[1] = m_transformableVertex[1].getY();
	vertex[27].coordinate[2] = m_transformableVertex[1].getZ();

	vertex[28].coordinate[0] = m_transformableVertex[4].getX();
	vertex[28].coordinate[1] = m_transformableVertex[4].getY();
	vertex[28].coordinate[2] = m_transformableVertex[4].getZ();

	vertex[29].coordinate[0] = m_transformableVertex[5].getX();
	vertex[29].coordinate[1] = m_transformableVertex[5].getY();
	vertex[29].coordinate[2] = m_transformableVertex[5].getZ();

	vertex[30].coordinate[0] = m_transformableVertex[2].getX();
	vertex[30].coordinate[1] = m_transformableVertex[2].getY();
	vertex[30].coordinate[2] = m_transformableVertex[2].getZ();

	vertex[31].coordinate[0] = m_transformableVertex[3].getX();
	vertex[31].coordinate[1] = m_transformableVertex[3].getY();
	vertex[31].coordinate[2] = m_transformableVertex[3].getZ();

	vertex[32].coordinate[0] = m_transformableVertex[6].getX();
	vertex[32].coordinate[1] = m_transformableVertex[6].getY();
	vertex[32].coordinate[2] = m_transformableVertex[6].getZ();

	vertex[33].coordinate[0] = m_transformableVertex[3].getX();
	vertex[33].coordinate[1] = m_transformableVertex[3].getY();
	vertex[33].coordinate[2] = m_transformableVertex[3].getZ();

	vertex[34].coordinate[0] = m_transformableVertex[6].getX();
	vertex[34].coordinate[1] = m_transformableVertex[6].getY();
	vertex[34].coordinate[2] = m_transformableVertex[6].getZ();

	vertex[35].coordinate[0] = m_transformableVertex[7].getX();
	vertex[35].coordinate[1] = m_transformableVertex[7].getY();
	vertex[35].coordinate[2] = m_transformableVertex[7].getZ();*/

	int temptIndex = 0;
	for (int i = 0; i < 8; i++)//Setting the Passing values to the correct numbers
	{
		temptIndex = i * 3;
		m_vertexArray[temptIndex] = m_transformableVertex[i].getX();//Takes the transformable Vectors and turns them into 3 double values
		m_vertexArray[temptIndex + 1] = m_transformableVertex[i].getY();
		m_vertexArray[temptIndex + 2] = m_transformableVertex[i].getZ();
	}
	temptIndex = 0;
	for (int i = 0; i < 36; i++)
	{
		vertex[i].coordinate[0] = m_vertexArray[vertex_index[i]*3];//For Each vertex applies the co ordinates of the required corner dictated by the vertex index.
		vertex[i].coordinate[1] = m_vertexArray[vertex_index[i]*3+1];
		vertex[i].coordinate[2] = m_vertexArray[vertex_index[i]*3+2];
	}

}

void Game::transformVertices()
{
	for (int i = 0; i < 8; i++)
	{
		m_transformableVertex[i] = m_transformableVertex[i] * m_Matrix;//Applies the transformation matrix to all transformable Vertices
	}
}

