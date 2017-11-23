class Field
{
private:
	int mas[24];
public:
	Field()
	{
		*mas = NULL;
	}
	Field(int *mas, bool *Activiti)
	{
		*this->mas = *mas;
	}
	Field(Field &z)
	{
		*this->mas = *z.mas;
	}
	void SetOnePawn(int Out, int In)
	{
		mas[Out] = In;
	}
	int *GetAllPawn()
	{
		return mas;
	}
	int ReturnOnePawn(int Out)
	{
		return mas[Out];
	}
};