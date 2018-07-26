#include <iostream>

using namespace std;

void ShowField(char (f)[3][3])
{
	cout << "Ваше поле:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " "  << f[i][j];
		}
		cout << endl;
	}
}

bool end(char(f)[3][3], int *MaxSteps)
{
	if ((((f[0][0] == f[1][1]) && (f[1][1] == f[2][2])) || (f[0][2] == f[1][1] && f[1][1] == f[2][0])) && (f[1][1] != char(42)))
	{
		if (f[1][1] == char(88))
		{
			ShowField(f);
			cout << endl << "Победа!" << endl;
			return true;
		} else
		{
			ShowField(f);
			cout << endl << "Поражение!" << endl;
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (((f[i][0] == f[i][1]) && (f[i][1] == f[i][2])) && !(f[i][1] == char(42)))
		{
			if (f[i][1] == char(88))
			{
				ShowField(f);
				cout << endl << "Победа!" << endl;
				return true;
			} else
			{
				ShowField(f);
				cout << endl << "Поражение!" << endl;
				return true;
			}
		}

		if (((f[0][i] == f[1][i]) && (f[1][i] == f[2][i])) && !(f[1][i] == char(42)))
		{
			if (f[1][i] == char(88))
			{
				ShowField(f);
				cout << endl << "Победа!" << endl;
				return true;
			} else
			{
				ShowField(f);
				cout << endl << "Поражение!" << endl;
				return true;
			}
		}
	}

	if (*MaxSteps == 0)
	{
		ShowField(f);
		cout << endl << "Ничья!" << endl;
		return true;
	}
	return false;
}

bool input(char(f)[3][3], int *MaxSteps, bool *step)
{
	int n = 0;
	int i, j;

	cout << "Ваш ход!" << endl;
	cin >> n;
	if (n < 1 || n > 9)
	{
		cout << "Неверный ввод!" << endl;
		return false;
	}

	if (n % 3 == 0)
	{
		i = n / 3 - 1;
		j = 2;
	} else
	{
		i = n / 3;
		j = n % 3 - 1;
	}

	if (f[i][j] != char(42)) 
	{
		cout << "Ячейка уже знята!" << endl;
		return false;
	} else
	{
		f[i][j] = char(88);
		*MaxSteps -= 1;
		*step = false;
		return true;
	}
	return false;
}

bool BotStep(char (f)[3][3], int *MaxSteps, bool *step)
{
	if ((((f[0][0] == char(48) && f[2][2] == char(48)) || (f[2][0] == char(48) && f[0][2] == char(48))) || ((f[0][0] == char(88) && f[2][2] == char(88)) || (f[2][0] == char(88) && f[0][2] == char(88)))) && f[1][1] == char(42))
	{
		cout << "Ход компютера!" << endl;
		f[1][1] = char(48);
		*MaxSteps -= 1;
		*step = true;
		return true;
	} else
		if (((f[0][0] == char(48) && f[1][1] == char(48)) || (f[0][0] == char(88) && f[1][1] == char(88))) && f[2][2] == char(42) )
		{
			cout << "Ход компютера!" << endl;
			f[2][2] = char(48);
			*MaxSteps -= 1;
			*step = true;
			return true;
		} else
			if (((f[1][1] == char(48) && f[2][2] == char(48)) || (f[1][1] == char(88) && f[2][2] == char(88))) && f[0][0] == char(42))
			{
				cout << "Ход компютера!" << endl;
				f[0][0] = char(48);
				*MaxSteps -= 1;
				*step = true;
				return true;
			} else
				if (((f[0][2] == char(48) && f[1][1] == char(48)) || (f[0][2] == char(88) && f[1][1] == char(88))) && f[2][0] == char(42))
				{
					cout << "Ход компютера!" << endl;
					f[2][0] = char(48);
					*MaxSteps -= 1;
					*step = true;
					return true;
				} else
					if (((f[1][1] == char(48) && f[2][0] == char(48)) || (f[1][1] == char(88) && f[2][0] == char(88))) && f[0][2] == char(42))
					{
						cout << "Ход компютера!" << endl;
						f[0][2] = char(48);
						*MaxSteps -= 1;
						*step = true;
						return true;
					} else
						if (1)
						{
							for (int i = 0; i < 3; i++)
							{
								if (((f[i][0] == char(48) && (f[i][1] == char(48))) || (f[i][0] == char(88) && (f[i][1] == char(88)))) && f[i][2] == char(42))
								{
									cout << "Ход компютера!" << endl;
									f[i][2] = char(48);
									*MaxSteps -= 1;
									*step = true;
									return true;
								} else
									if (((f[i][2] == char(48) && (f[i][1] == char(48))) || (f[i][2] == char(88) && (f[i][1] == char(88)))) && f[i][0] == char(42))
									{
										cout << "Ход компютера!" << endl;
										f[i][0] = char(48);
										*MaxSteps -= 1;
										*step = true;
										return true;
									} else
										if (((f[i][0] == char(48) && (f[i][2] == char(48))) || (f[i][0] == char(88) && (f[i][2] == char(88)))) && f[i][1] == char(42))
										{
											cout << "Ход компютера!" << endl;
											f[i][1] = char(48);
											*MaxSteps -= 1;
											*step = true;
											return true;
										}

									if (((f[0][i] == char(48) && (f[1][i] == char(48))) || (f[0][i] == char(88) && (f[1][i] == char(88)))) && f[2][i] == char(42))
									{
										cout << "Ход компютера!" << endl;
										f[2][i] = char(48);
										*MaxSteps -= 1;
										*step = true;
										return true;
									} else
										if (((f[2][i] == char(48) && (f[1][i] == char(48))) || (f[2][i] == char(88) && (f[1][i] == char(88)))) && f[0][i] == char(42))
										{
											cout << "Ход компютера!" << endl;
											f[0][i] = char(48);
											*MaxSteps -= 1;
											*step = true;
											return true;
										} else
											if (((f[0][i] == char(48) && (f[2][i] == char(48))) || (f[0][i] == char(88) && (f[2][i] == char(88)))) && f[1][i] == char(42))
											{
												cout << "Ход компютера!" << endl;
												f[1][i] = char(48);
												*MaxSteps -= 1;
												*step = true;
												return true;
											}
							}
						} 
	for (int i = 0; i < 3; i++)
		for (int j = 2; j >= 0; j--)
		{
			if (f[i][j] == char(42))
			{
				cout << "Ход компютера!" << endl;
				f[i][j] = char(48);
				*MaxSteps -= 1;
				*step = true;
				return true;
			}
		}
	return true;
}

int main() 
{
	setlocale(LC_ALL, "Russian");

	char field[3][3];
	int MaxSteps = 9;
	bool step = true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			field[i][j] = char(42); 
		}
	cout << "Нумерация клеток поля выглядит следующим образом: \n 1 2 3\n 4 5 6\n 7 8 9\n\n";

	while (!end(field,&MaxSteps))
	{
		
		ShowField(field);
		if (step)
		{
			input(field, &MaxSteps, &step);
		} else
		{
			BotStep(field,&MaxSteps, &step);
		}
		//system("cls");
	};
	system("pause");
	return 0;
}