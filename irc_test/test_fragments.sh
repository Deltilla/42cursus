#!/bin/bash

# test_fragments.sh
# Script para probar manejo de comandos fragmentados

echo "======================================"
echo "Test: Manejo de Fragmentos en IRC"
echo "======================================"
echo ""

# Compilar
echo "[1] Compilando servidores..."
make clean > /dev/null 2>&1
make > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "❌ Error en compilación"
    exit 1
fi
echo "✅ Compilación exitosa"
echo ""

# Obtener puerto disponible
PORT=6667

echo "[2] Iniciando mini_irc_test en puerto $PORT..."
./mini_irc_test $PORT &
SERVER_PID=$!
sleep 1

if ! kill -0 $SERVER_PID 2>/dev/null; then
    echo "❌ No se pudo iniciar servidor"
    exit 1
fi
echo "✅ Servidor iniciado (PID=$SERVER_PID)"
echo ""

echo "[3] Prueba 1: Comando fragmentado (com + man + d)"
echo ""
{
    printf "com"
    sleep 0.1
    printf "man"
    sleep 0.1
    printf "d\n"
    sleep 0.2
} | nc -q 1 127.0.0.1 $PORT | cat
echo ""

echo "[4] Prueba 2: Múltiples comandos en una sola conexión"
echo ""
{
    printf "hello\n"
    sleep 0.1
    printf "world\n"
    sleep 0.2
} | nc -q 1 127.0.0.1 $PORT | cat
echo ""

echo "[5] Prueba 3: Fragmentación con salto de línea en el medio"
echo ""
{
    printf "lin"
    sleep 0.05
    printf "e1\nline2\n"
    sleep 0.2
} | nc -q 1 127.0.0.1 $PORT | cat
echo ""

# Limpiar
kill $SERVER_PID 2>/dev/null
wait $SERVER_PID 2>/dev/null

echo "======================================"
echo "✅ Pruebas completadas"
echo "======================================"
