/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:02:03 by ttrave            #+#    #+#             */
/*   Updated: 2024/11/28 20:18:10 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp(void);
	std::cout << " index:" << index << ";amount:" << initial_deposit << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp(void);
	std::cout << " index:" << index << ";amount:" << initial_deposit << ";closed" << std::endl;
}

static int	getNbAccounts(void)
{
	return (_nbAccounts);
}

static int	getTotalAmount(void)
{
	return (_totalAmount);
}

static int	getNbDeposits(void)
{
	return (_totalNbDeposits);
}

static int	getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

static void	displayAccountsInfos(void)
{
	_displayTimestamp(void);
	std::cout << " accounts:" << getNbAccounts(void) << ";total:" << getTotalAmount(void) << ";deposits:" << getNbDeposits(void) << ";withdrawals:" << getNbWithdrawals(void) << std::endl;
}

void	makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	// txt
}

bool	makeWithdrawal(int withdrawal)
{
	_totalNbWithdrawals++;
	if (withdrawal > _amount)
	{
		// txt, refused
		return (1);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	return (0);
	//txt
}

int	checkAmount(void)
{
	// a quoi sert cette fonction ???
}

void	displayStatus(void)
{
	_displayTimestamp(void);
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

static void	_displayTimestamp(void)
{
	// quel format ? quelle fonction ?
}
