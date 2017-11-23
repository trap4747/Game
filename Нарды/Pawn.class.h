class Pawn
{
private:
	FLOAT TopLeftPointX;
	FLOAT TopLeftPointY;
	FLOAT BottomRightPointX;
	FLOAT BottomRightPointY;
	BOOL Activiti;
	INT PositionField;
public:
	Pawn()
	{
		TopLeftPointX = NULL;
		TopLeftPointY = NULL;
		BottomRightPointX = NULL;
		BottomRightPointY = NULL;
		Activiti = NULL;
		PositionField = NULL;
	}
	Pawn(FLOAT TopLeftPointX, FLOAT TopLeftPointY, FLOAT BottomRightPointX, FLOAT BottomRightPointY, BOOL Activiti, INT PositionField)
	{
		this->TopLeftPointX = TopLeftPointX;
		this->TopLeftPointY = TopLeftPointY;
		this->BottomRightPointX = BottomRightPointX;
		this->BottomRightPointY = BottomRightPointY;
		this->Activiti = Activiti;
		this->PositionField = PositionField;
	}
	Pawn(Pawn &z)
	{
		this->TopLeftPointX = z.TopLeftPointX;
		this->TopLeftPointY = z.TopLeftPointY;
		this->BottomRightPointX = z.BottomRightPointX;
		this->BottomRightPointY = z.BottomRightPointY;
		this->Activiti = z.Activiti;
		this->PositionField = z.PositionField;
	}
	void SetTopLeftPointX(FLOAT z)
	{
		TopLeftPointX = z;
	}
	void SetTopLeftPointY(FLOAT z)
	{
		TopLeftPointY = z;
	}
	void SetBottomRightPointX(FLOAT z)
	{
		BottomRightPointX = z;
	}
	void SetBottomRightPointY(FLOAT z)
	{
		BottomRightPointY = z;
	}
	void SetActiviti(BOOL z)
	{
		Activiti = z;
	}
	void SetPositionField(INT z)
	{
		PositionField = z;
	}
	FLOAT GetTopLeftPointX()
	{
		return TopLeftPointX;
	}
	FLOAT GetTopLeftPointY()
	{
		return TopLeftPointY;
	}
	FLOAT GetBottomRightPointX()
	{
		return BottomRightPointX;
	}
	FLOAT GetBottomRightPointY()
	{
		return BottomRightPointY;
	}
	BOOL GetActiviti()
	{
		return Activiti;
	}
	INT GetPositionField()
	{
		return PositionField;
	}
	VOID MoveRight(int NumberPawn, bool ColorPawn, int z)
	{
		if (!ColorPawn)
		{
			if ((PositionField + mas[z]) < 12 && PositionField < 12)
			{
				for (int j = 0; j < mas[z]; j++)
				{
					TopLeftPointX = TopLeftPointX + Move_Right[PositionField + j];
					BottomRightPointX = BottomRightPointX + Move_Right[PositionField + j];
				}
				MoveBottom(NumberPawn, false, z);
			}
			else if ((PositionField + mas[z]) < 24 && (PositionField + mas[z]) >= 12 && PositionField < 12)
			{
				for (int j = PositionField + 1; j < 12; j++)
				{
					TopLeftPointX = TopLeftPointX + Move_Right[PositionField + j];
					BottomRightPointX = BottomRightPointX + Move_Right[PositionField + j];
				}
				MoveLeft(NumberPawn, false, z);
			}
		}
		else
		{
			if ((PositionField + mas[z]) < 12)
			{
				for (int j = 0; j < mas[z]; j++)
				{
					TopLeftPointX = TopLeftPointX + Move_Right[PositionField + j];
					BottomRightPointX = BottomRightPointX + Move_Right[PositionField + j];
				}
				MoveBottom(NumberPawn, true, z);
			}
			if ((PositionField + mas[z]) >= 24)
			{
				int ram = 23 - PositionField;
				MoveBottom(NumberPawn, PositionField + mas[z] - 24, true, 1);
				for (int j = 0; j < mas[z] - ram - 1; j++)
				{
					TopLeftPointX = TopLeftPointX + Move_Right[0 + j];
					BottomRightPointX = BottomRightPointX + Move_Right[0 + j];
				}
			}
		}
	}
	VOID MoveLeft(int NumberPawn, bool ColorPawn, int z)
	{
		if (!ColorPawn)
		{
			if ((PositionField + mas[z]) < 24 && (PositionField + mas[z]) >= 12
				&& PositionField < 24 && PositionField >= 12)
			{
				for (int j = 0; j < mas[z]; j++)
				{
					TopLeftPointX = TopLeftPointX - Move_Left[PositionField + j - 12];
					BottomRightPointX = BottomRightPointX - Move_Left[PositionField + j - 12];
				}
				MoveTop(NumberPawn, false, z);
			}
			else if ((PositionField + mas[z]) < 24 && (PositionField + mas[z]) >= 12
				&& PositionField < 12)
			{
				MoveTop(NumberPawn, (PositionField + mas[z]) - 12, false, 1);
				for (int j = 12; j < (PositionField + mas[z]); j++)
				{
					TopLeftPointX = TopLeftPointX - Move_Left[j - 12];
					BottomRightPointX = BottomRightPointX - Move_Left[j - 12];
				}
			}
		}
		else
		{
			if ((PositionField + mas[z]) < 24 && (PositionField + mas[z]) >= 12
				&& PositionField < 24 && PositionField >= 12)
			{
				for (int j = 0; j < mas[z]; j++)
				{
					TopLeftPointX = TopLeftPointX - Move_Left[PositionField + j - 12];
					BottomRightPointX = BottomRightPointX - Move_Left[PositionField + j - 12];
				}
				MoveTop(NumberPawn, true, z);
			}
			else if (PositionField < 24 && PositionField >= 12
				&& (PositionField + mas[z]) >= 24)
			{
				int r = 0;
				for (int j = PositionField + 1; j < 24; j++)
				{
					TopLeftPointX = TopLeftPointX - Move_Left[PositionField + r - 12];
					BottomRightPointX = BottomRightPointX - Move_Left[PositionField + r - 12];
					r++;
				}
				MoveRight(NumberPawn, true, z);
			}
			else if ((PositionField + mas[z]) < 12)
			{
				for (int j = 0; j < mas[z]; j++)
				{
					TopLeftPointX = TopLeftPointX + Move_Right[PositionField + j];
					BottomRightPointX = BottomRightPointX + Move_Right[PositionField + j];
				}
				MoveBottom(NumberPawn, true, z);
			}
		}
	}
	VOID MoveBottom(int NumberPawn, int NewPoisition, bool ColorPawn, int mysor)
	{
		if (ColorPawn)
		{
			int z = 0, q = 0;
			while (true)
			{
				if (abs(All_Field.ReturnOnePawn(NewPoisition)) >= q)
				{
					TopLeftPointX = 50.0f;
					TopLeftPointY = 540.0f - z;
					BottomRightPointX = 100.0f;
					BottomRightPointY = 490.0f - z;
					z += 25;
					q++;
				}
				else
					break;
			}
		}
	}
	VOID MoveBottom(int NumberPawn, bool ColorPawn, int z)
	{
		if (!ColorPawn)
		{
			if (All_Field.ReturnOnePawn(PositionField) > All_Field.ReturnOnePawn(PositionField + mas[z]))
			{
				for (int j = All_Field.ReturnOnePawn(PositionField + mas[z]); j < All_Field.ReturnOnePawn(PositionField) - 1; j++)
				{
					TopLeftPointY = TopLeftPointY + 25;
					BottomRightPointY = BottomRightPointY + 25;
				}
			}
			else
			{
				int zp = All_Field.ReturnOnePawn(PositionField + mas[z]) - All_Field.ReturnOnePawn(PositionField);
				for (int j = 0; j < zp + 1; j++)
				{
					TopLeftPointY = TopLeftPointY - 25;
					BottomRightPointY = BottomRightPointY - 25;
				}
			}
		}
		else
		{
			if (abs(All_Field.ReturnOnePawn(PositionField)) > abs(All_Field.ReturnOnePawn(PositionField + mas[z])))
			{
				for (int j = abs(All_Field.ReturnOnePawn(PositionField + mas[z])); j < abs(All_Field.ReturnOnePawn(PositionField)) - 1; j++)
				{
					TopLeftPointY = TopLeftPointY + 25;
					BottomRightPointY = BottomRightPointY + 25;
				}
			}
			else
			{
				int zp = abs(All_Field.ReturnOnePawn(PositionField + mas[z])) - abs(All_Field.ReturnOnePawn(PositionField));
				for (int j = 0; j < zp + 1; j++)
				{
					TopLeftPointY = TopLeftPointY - 25;
					BottomRightPointY = BottomRightPointY - 25;
				}
			}
		}
	}
	VOID MoveTop(int NumberPawn, int NewPoisition, bool ColorPawn, int mysor)
	{
		if (!ColorPawn)
		{
			int z = 0, q = 0;
			while (true)
			{
				if (abs(All_Field.ReturnOnePawn(NewPoisition + 12)) >= q)
				{
					TopLeftPointX = 708.0f;
					TopLeftPointY = 78.0f + z;
					BottomRightPointX = 758.0f;
					BottomRightPointY =27.0f + z;
					z += 25;
					q++;
				}
				else
					break;
			}
		}
	}
	VOID MoveTop(int NumberPawn, bool ColorPawn, int z)
	{
		if (!ColorPawn)
		{
			if (All_Field.ReturnOnePawn(PositionField) > All_Field.ReturnOnePawn(PositionField + mas[z]))
			{
				for (int j = All_Field.ReturnOnePawn(PositionField + mas[z]); j < All_Field.ReturnOnePawn(PositionField) - 1; j++)
				{
					TopLeftPointY = TopLeftPointY - 25;
					BottomRightPointY = BottomRightPointY - 25;
				}
			}
			else
			{
				int zp = All_Field.ReturnOnePawn(PositionField + mas[z]) - All_Field.ReturnOnePawn(PositionField);
				for (int j = 0; j < zp + 1; j++)
				{
					TopLeftPointY = TopLeftPointY + 25;
					BottomRightPointY = BottomRightPointY + 25;
				}
			}
		}
		else
		{
			if (abs(All_Field.ReturnOnePawn(PositionField)) > abs(All_Field.ReturnOnePawn(PositionField + mas[z])))
			{
				for (int j = abs(All_Field.ReturnOnePawn(PositionField + mas[z])); j < abs(All_Field.ReturnOnePawn(PositionField)) - 1; j++)
				{
					TopLeftPointY = TopLeftPointY - 25;
					BottomRightPointY = BottomRightPointY - 25;
				}
			}
			else
			{
				int zp = abs(All_Field.ReturnOnePawn(PositionField + mas[z])) - abs(All_Field.ReturnOnePawn(PositionField));
				for (int j = 0; j < zp + 1; j++)
				{
					TopLeftPointY = TopLeftPointY + 25;
					BottomRightPointY = BottomRightPointY + 25;
				}
			}
		}

	}
};