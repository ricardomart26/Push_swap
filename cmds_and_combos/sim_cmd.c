#include "../push_swap.h"

// int do_rr_top(moves_t *cmd, stacks_t ***temp) // Dont know if it works
// {
//     if (cmd->rb == cmd->ra)
//     {
//         cmd = rr_sim(cmd, cmd->ra, 0, 0);
//         ***temp = gen_moves(***temp, 4, cmd->rr, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rb > cmd->ra)
//     {
//         cmd = rr_sim(cmd, cmd->ra, cmd->rb -= cmd->ra, 0);
//         ***temp = gen_moves(***temp, 4, cmd->rr, 0);
//         ***temp = gen_moves(***temp, 2, cmd->rb, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rb < cmd->ra)
//     {
//         cmd = rr_sim(cmd, cmd->rb, 0, cmd->ra -= cmd->rb);
//         ***temp = gen_moves(***temp, 4, cmd->rr, 0);
//         ***temp = gen_moves(***temp, 0, cmd->ra, 1);
//         return (cmd->total);
//     }
//     return (0);
// }

// int do_rrr_bottom(moves_t *cmd, stacks_t ***temp)
// {
//     if (cmd->rrb == cmd->rra)
//     {
//         cmd = rrr_sim(cmd, cmd->rra, 0, 0);
//         ***temp = gen_moves(***temp, 5, cmd->rrr, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rrb > cmd->rra)
//     {
//         cmd = rrr_sim(cmd, cmd->rra, cmd->rrb -= cmd->rra, 0);
//         ***temp = gen_moves(***temp, 5, cmd->rrr, 0);
//         ***temp = gen_moves(***temp, 3, cmd->rrb, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rrb < cmd->rra)
//     {
//         cmd = rrr_sim(cmd, cmd->rrb, 0, cmd->rra -= cmd->rrb);
//         ***temp = gen_moves(***temp, 5, cmd->rrr, 0);
//         ***temp = gen_moves(***temp, 1, cmd->rra, 1);
//         return (cmd->total);
//     }
//     return (0);
// }

// int move_down_the_stack(stacks_t **temp, int place, moves_t cmd)
// {
//     int size;

//     size = (*temp)->sizeB;
//     cmd.rrb = size - place;
//     if (cmd.ra)
//     {
//         **temp = gen_moves(**temp, 0, cmd.ra, 0);
//         **temp = gen_moves(**temp, 3, cmd.rrb, 1);
//         return (cmd.ra + cmd.rrb + pb);
//     }
//     else if (cmd.rra)
//         return (do_rrr_bottom(&cmd, &temp));
//     else
//     {
//         **temp = gen_moves(**temp, 3, cmd.rrb, 1);
//         return (cmd.rrb + pb);
//     }

// }

// int move_top_of_stack(stacks_t **temp, int place, moves_t cmd)
// {
//     cmd.rb = place;
//     if (cmd.num == 21)
//     {
//         printf("(move top of stack) rb %d\n", cmd.rb);
//         print_stacks(**temp);
//         sleep(3);
//     }
    
//     if (cmd.rra)
//     {
//         **temp = gen_moves(**temp, 1, cmd.rra, 0);
//         **temp = gen_moves(**temp, 2, cmd.rb, 1);
//         return (cmd.ra + cmd.rrb + pb);
//     }
//     else if (cmd.ra)
//         return (do_rr_top(&cmd, &temp));
//     else
//         **temp = gen_moves(**temp, 2, cmd.rb, 1);

//     return (cmd.rra + pb);
// }

int num1(stacks_t **temp, moves_t cmd)
{
    // print_cmds(&cmd, 0);
    // sleep(2);
    if (cmd.rr && !cmd.ra && !cmd.rb)
    {
        
        **temp = gen_moves(**temp, 4, cmd.rr, 1);
        if ((*temp)->stackB[0] > 513)
        {
            print_stacks(**temp);
            print_cmds(&cmd, 0);
            printf("\n\tO suposto e ser este numero %d\n", cmd.num);
            sleep(3);
        }
        return(cmd.rr + pb);
    }
    else if (cmd.rr)
    {
        **temp = gen_moves(**temp, 4, cmd.rr, 0);
        **temp = gen_moves(**temp, 0, cmd.ra, 0);
        **temp = gen_moves(**temp, 2, cmd.rb, 0);
        **temp = gen_moves(**temp, 3, cmd.rrb, 1);
        if ((*temp)->stackB[0] > 513)
        {
            print_stacks(**temp);
            print_cmds(&cmd, 0);
            printf("\n\tO suposto e ser este numero %d\n", cmd.num);
            sleep(3);
        }
        return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + pb);
    }
    else if (!cmd.rr)
    {

        **temp = gen_moves(**temp, 0, cmd.ra, 0);
        **temp = gen_moves(**temp, 2, cmd.rb, 0);
        **temp = gen_moves(**temp, 3, cmd.rrb, 0);
        **temp = pb_funct(**temp);
        if ((*temp)->stackB[0] > 513)
        {
            print_stacks(**temp);
            print_cmds(&cmd, 0);
            printf("\n\tO suposto e ser este numero %d\n", cmd.num);
            sleep(3);
        }
        // printf("\n\tteste 3\n");
        // print_stacks(**temp);
        // sleep(3);
        return (cmd.ra + cmd.rb + cmd.rrb + pb);
    }
    return (0);
}

int num2(stacks_t **temp, moves_t cmd)
{
    print_cmds(&cmd, 0);
    print_stacks(**temp);
    if (cmd.rrr && !cmd.rra && !cmd.rrb)
    {
        **temp = gen_moves(**temp, 5, cmd.rrr, 1);
        if ((*temp)->stackB[0] > 513)
        {
            print_stacks(**temp);
            print_cmds(&cmd, 0);
            printf("\n\tO suposto e ser este numero %d\n", cmd.num);
            sleep(3);
        }
        return(cmd.rrr + pb);
    }
    else if (cmd.rrr)
    {
        **temp = gen_moves(**temp, 5, cmd.rrr, 0);
        **temp = gen_moves(**temp, 1, cmd.rra, 0);
        **temp = gen_moves(**temp, 3, cmd.rrb, 0);
        **temp = gen_moves(**temp, 2, cmd.rb, 1);
        if ((*temp)->stackB[0] > 513)
        {
            print_stacks(**temp);
            print_cmds(&cmd, 0);
            printf("\n\tO suposto e ser este numero %d\n", cmd.num);
            sleep(3);
        }
        return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + pb);
    }
    else if (!cmd.rrr)
    {
        **temp = gen_moves(**temp, 1, cmd.rra, 0);
        **temp = gen_moves(**temp, 2, cmd.rb, 0);
        **temp = gen_moves(**temp, 3, cmd.rrb, 1);
        if ((*temp)->stackB[0] > 513)
        {
            print_stacks(**temp);
            print_cmds(&cmd, 0);
            printf("\n\tO suposto e ser este numero %d\n", cmd.num);
            sleep(3);
        } 
        return (cmd.rra + cmd.rb + cmd.rrb + pb);
    }
    return (0);
}