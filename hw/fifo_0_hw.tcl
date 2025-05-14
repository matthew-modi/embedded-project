# fifo_0_hw.tcl — device‐tree bindings for the Avalon-FIFO at instance fifo_0

# What vendor string to use in the DT
set_module_assignment embeddedsw.dts.vendor     "csee4840"
# What the DT node name should be (driver will look for this)
set_module_assignment embeddedsw.dts.name       "camera_fifo"
# What the DT compatible string should be
set_module_assignment embeddedsw.dts.compatible "csee4840,camera-fifo"
# Grouping so it sorts under the same bus in the DT
set_module_assignment embeddedsw.dts.group      "camera_io"

