OBJDIR = obj_dir

target ?= top
sim ?= 1
view ?= 1

SIM_CPP = sim_$(target)_$(sim).cpp
SIM_VIEW = view_$(target)_$(sim)_$(view).gtkw

default:
	verilator --sv -Wall -Wno-UNOPTFLAT -Wno-UNUSED --cc $(target).sv --exe $(SIM_CPP) --trace
	make -C $(OBJDIR) -f V$(target).mk V$(target)
	./$(OBJDIR)/V$(target)
	gtkwave dump.vcd $(SIM_VIEW)

clean:
	rm -rf $(OBJDIR) dump.vcd