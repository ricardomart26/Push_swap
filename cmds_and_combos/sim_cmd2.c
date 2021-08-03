#include "../push_swap.h"

stacks_t   gen_moves(stacks_t main, int option, int counter, int pb_pa)
{
    // if (counter > 20)
    //     sleep(20);
    while (counter)
    {
        if (option == 0)
            main = ra_funct(main, 1);
        if (option == 1)
            main = rra_funct(main, 1);
        if (option == 2)
            main = rb_funct(main, 1);
        if (option == 3)
            main = rrb_funct(main, 1);
        if (option == 4)
            main = rr_funct(main);
        if (option == 5)
            main = rrr_funct(main);
        counter--;
    }
    if (pb_pa == 1)
        main = pb_funct(main);
    else if (pb_pa == 2)
        main = pa_funct(main);

    return (main);
}

moves_t *rr_sim(moves_t *cmd, int rr, int ra, int rb)
{
    cmd->rr = rr;
    cmd->ra = ra;
    cmd->rb = rb;
    cmd->total = cmd->rr + cmd->ra + cmd->rb;
    return (cmd);
}

moves_t *rrr_sim(moves_t *cmd, int rrr, int rrb, int rra)
{
    cmd->rrr = rrr;
    cmd->rrb = rrb;
    cmd->rra = rra;
    cmd->total = cmd->rrr + cmd->rra + cmd->rrb;
    return (cmd);
}