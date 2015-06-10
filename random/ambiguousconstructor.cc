class Ball
{
	public:
		Ball()
		{
			m_radius = 0;
			m_colour = 0;
		}

		Ball(double radius = 0.0, int colour = 0)
		{
		}

	private:
		int m_radius;
		int m_colour;
};

int main()
{
	Ball a;
}
