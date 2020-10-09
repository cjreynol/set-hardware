#include "pch.h"

#include "CppUnitTest.h"

#include "../Game.h"
#include "../GameManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{

	TEST_CLASS(GameTests)
	{
	public:
		GameTests()
			: _game()
		{
		}

		TEST_METHOD(Unitialized_Game_Has_No_Set)
		{
			Assert::IsFalse(Set::GameManager::Has_Set(_game));
		}

	private:
        Set::Game _game;
	};
}
