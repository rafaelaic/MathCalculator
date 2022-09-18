# MathCalculator
<p>A math calculator made in C</p>

## How it Works
<p>In <strong>1.0 version</strong> you can calculate math expressions, declare variables and use commands.</p>

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
        <strong><p>The result is saved in $s special var</p></srtong>
    </li>
</ul>


### Supported operators
<p>The operators supported are:</p>
 <code><strong>+ - * / ^</strong></code>

<p>Only parentheses <strong>( )</strong> are supported.</p>

<p> The only variable registered in this version is <code><strong>pi</strong> = 3.141592</code></p>

## Examples

<code>>> (23 - 67)*(343)</code>
<br>
<code>-15092.00</code>
<br>
<code>>> pi * 3</code>
<br>
<code>9.42</code>
<br>
<code>love=100</code>
<br>
<code>>> listvar</code>
<br>
<code>
-------------------------------
|        Variables List       |
-------------------------------
love -> 100.00
$s -> 9.42
$pi -> 3.14
</code>

## How to install
<p>Just clone this repository and run:</p>
<code>make && make run</code>


