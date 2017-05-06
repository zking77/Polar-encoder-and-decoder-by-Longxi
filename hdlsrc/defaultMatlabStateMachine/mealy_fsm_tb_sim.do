onbreak resume
onerror resume
vsim -novopt work.mealy_fsm_tb
add wave sim:/mealy_fsm_tb/u_mealy_fsm/clk
add wave sim:/mealy_fsm_tb/u_mealy_fsm/reset
add wave sim:/mealy_fsm_tb/u_mealy_fsm/clk_enable
add wave sim:/mealy_fsm_tb/u_mealy_fsm/In1
add wave sim:/mealy_fsm_tb/u_mealy_fsm/ce_out
add wave sim:/mealy_fsm_tb/u_mealy_fsm/Out1
add wave sim:/mealy_fsm_tb/Out1_ref
run -all
