# MathCalculator
<p>A math calculator made in C</p>

## How it Works
<p>In <strong>1.1 version</strong> you can calculate math expressions, declare variables and use commands.</p>

<p>The calculator has 3 command modes, starting from an input expression.</p>

<ul>
    <li>
        <h3>Command Mode</h3>
        <p>Execute commands like listvar, listcommands, clear, and more.</p>
    </li>
    <li>
        <h3>Variable Declaration Mode</h3>
        <p>Declare variables with expressions like <code>var_name=math expression</code></p>
    </li>
    <li>
        <h3>Math Expression Calculate</h3>
        <p>Calculate math expressions like <code>(124 / 4) * $pi</code></p>
        <strong><p>The result is saved in $s special var</p></strong>
    </li>
</ul>


## Supported operators
<p>The operators supported are:</p>
 <strong><code>+ - * / ^</code></strong>

<p>Only parentheses <strong>( )</strong> are supported.</p>

## Examples
<pre><code>
>> (23 - 67)*(343)
-15092.00
>> $pi * 3
9.42
>> love=100
>> listvar
-------------------------------
|        Variables List       |
-------------------------------
love -> 100.00
$s -> 9.42
$pi -> 3.14
>> listcommands
-------------------------------
|        Commands List        |
-------------------------------
listcommands -> List the registered commands
listvar -> List the registered variables
clear -> Clear the CLI
exit -> Exit the program
</code></pre>


## How to install
<p>Just clone this repository and run the build on ./bin/ according your OS.</p>
<p><strong>If you want compile your own build run: </strong></p>
<code>$ make && make run</code>
<p>or</p>
<code>$ gcc ./apps/MathCalculator ./src/* -I ./include -o ./bin/YourMathCalculatorBuild</code>



