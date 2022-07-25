# ***** Makefile
# ***** Author: Chappidi Yoga Satwik
# ***** Date: 07-Mar-2021
# ***** Version: 1.0
# ***** Known bugs: None

BUILD_DIR ?= .out

CXX := g++
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' ! -name ApplicationTest.cpp ! -name UnitTest.cpp  | sed 's|^./||')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)	

RunApplicationTest: ApplicationTest
	@./ApplicationTest

ApplicationTest: $(OBJS) ApplicationTest.cpp Settings.h SeniorCitizenStatics.h DivyaangStatics.h BookingClassStatics.h
	$(CXX) $(OBJS) ApplicationTest.cpp -o $@

RunUnitTest: UnitTest
	@./UnitTest

UnitTest: $(OBJS) UnitTest.cpp Settings.h SeniorCitizenStatics.h DivyaangStatics.h BookingClassStatics.h
	$(CXX) $(OBJS) UnitTest.cpp -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	$(MKDIR_P) $(BUILD_DIR)
	$(CXX) -c $< -o $@

.PHONY: clean

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f ApplicationTest
	@rm -f UnitTest

MKDIR_P ?= mkdir -p
