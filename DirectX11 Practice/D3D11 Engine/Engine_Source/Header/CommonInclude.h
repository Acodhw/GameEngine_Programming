//Todo : 앞으로 쓸 헤더파일들을 모아둡니다

// 기본 라이브러리
#include <Windows.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include<bitset>
#include <functional>
#include <filesystem>
#include <mutex>
#include <thread>
#include <cassert>

#include <mmsystem.h>
#include <dinput.h>
#include <functional>
#include <ostream>
#include <sstream>


// 사용자 지정 라이브러리
#include "PEMath.h"
#include "PEEnums.h"

#define BIT(x) (1 << x)
#define CAST_UINT(value) static_cast<UINT>(value)
#define CAST_FLOAT(value) static_cast<float>(value)

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = nullptr; }
#define SAFE_RELEASE(p) if (p) { p->Release(); p = nullptr; }

#define YA_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }